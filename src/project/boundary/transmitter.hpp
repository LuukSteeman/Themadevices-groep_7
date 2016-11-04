#ifndef TRANSMITTER_HPP
#define TRANSMITTER_HPP
#include "hwlib.hpp"
#include "rtos.hpp"

class transmitter : public due::d2_36kHz
{
public:
	transmitter();
	template<class T>
	void sendBit(bool bit, T * task)
	{
		set(true);
    	task->sleep((bit ? 1600 : 800) * rtos::us);
    	set(false);
    	task->sleep((bit ? 800 : 1600) * rtos::us);
	}
};

#endif //TRANSMITTER_HPP