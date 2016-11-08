///@file
#ifndef TRANSMITTERCTRL_HPP
#define TRANSMITTERCTR_HPP
#include "hwlib.hpp"
#include "rtos.hpp"
#include "transmitter.hpp"
#include "IRMessage.hpp"


///Transmitterctrl
//
///Transmitterctrl is an implementation of the rtos::task<> template.
///It knows a Transmitter and tells it what bits to send.
///Use the channel to communicate with this task from other tasks.
///The channel is made for IRMessages, it can contain up to 10.
///The channel is read as part of the main, if it contains an IRMessage, it will tell the transmitter what bits to send.

class Transmitterctrl : public rtos::task<>
{
private:
	///trans is the transmitter the controller uses to send IRMessages.
	Transmitter & trans;

	///chan is the channel on which the task receives its IRMessages.
	rtos::channel<IRMessage, 10> chan;

	///The main is an infinite while loop.
	///The main of a transmitterctrl task is automatically run when you use rtos::run in your main.cpp
	///First the main checks the channel, unless there's something in it, it just keeps repeating the loop.
	///Once there's a IRMessage object in the channel, encode function is run and the return value is stored in a short.
	///The corresponding bits are then send to the transmitter.
	void main();
public:

	///The Transmitterctrl constructor requires a name for debugging and a reference to a transmitter.
	Transmitterctrl(char * name, Transmitter & trans);

	///To communicate with Transmitterctrl task from other tasks, use the add() function to put IRMessage objects in the channel.
	void add(IRMessage m);
};

#endif //TRANSMITTERCTRL_HPP