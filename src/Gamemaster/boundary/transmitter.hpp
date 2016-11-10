#ifndef TRANSMITTER_HPP
#define TRANSMITTER_HPP
#include "hwlib.hpp"
#include "rtos.hpp"

///Transmitter class
//
///The transmitter class is an implementation of the due::d2_36kHz class.
///It has an extra function used to send a single bit using a certain protocol.
///With this protocol a single bit is made up out of three time segments, each 800 microseconds.
///The first segment is always high, the second segment is either high or low, which determines the value of the bit. The final segment is always low.
///The constructor of the due::d2_36kHz is used as no extra things are needed for the constructor.
class Transmitter : public due::d2_36kHz
{
public:

	///Sendbit
	//
	///sendBit() is a template function which can send a single bit on the d2 pin on the arduino.
	///@tparam class T has to be a class which implements the rtos::task<> template class, as the sleep function is used to produce the correct signal.
	///@param bool bit is the bit that will be send. If bit is true, the function will put a high signal on the pin for 1600 microseconds
	///then set it to low for 800 microseconds.
	///If the bit is false instead this is reversed.
	void sendBit(bool bit, rtos::task_base * task)
	{
		set(1);
    	task->sleep((bit ? 1600 : 800) * rtos::us);
    	set(0);
    	task->sleep((bit ? 800 : 1600) * rtos::us);
	}
};

#endif //TRANSMITTER_HPP