///@file
#ifndef TRANSMITTERCTRL_HPP
#define TRANSMITTERCTRL_HPP
#include "hwlib.hpp"
#include "rtos.hpp"
#include "transmitter.hpp"
#include "messageLogic.hpp"


///Transmitterctrl
//
///Transmitterctrl knows a Transmitter and tells it what bits to send.
///The run function is only called by the shootCtrl and is therefore part of the same task.

class Transmitterctrl
{
private:

	///trans is the transmitter the controller uses to send messageLogic.
	Transmitter & trans;

	///The main is an infinite while loop.
	///The main of a transmitterctrl task is automatically run when you use rtos::run in your main.cpp
	///First the main checks the channel, unless there's something in it, it just keeps repeating the loop.
	///Once there's a IRMessage object in the channel, encode function is run and the return value is stored in a short.
	///The corresponding bits are then send to the transmitter.
public:

	///The run function is called by the shootCtrl.
	///@param m is the message it's going to send.
	///@param task is a pointer to the task that called it. Required for calling the sleep function in the transmitter
	void run(MessageLogic m, rtos::task_base * task);

	///@param trans a reference to a transmitter object
	Transmitterctrl(Transmitter & trans);

};

#endif //TRANSMITTERCTRL_HPP