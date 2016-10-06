/// @file
#ifndef IRRECEIVER_HPP
#define IRRECEIVER_HPP

#include "hwlib.hpp"
#include "rtos.hpp"

class IRReceiver : public rtos::task<>
{
private:
	int ir_pin;
	int out_pin;
	short msg;
	int last_bit;

public: 
	void detect();
	void main();

};

#endif //IRRECEIVER_HPP