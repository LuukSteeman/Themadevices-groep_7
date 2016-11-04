#ifndef TRANSMITTERCTRL_HPP
#define TRANSMITTERCTR_HPP
#include "hwlib.hpp"
#include "rtos.hpp"
#include "transmitter.hpp"
#include "IRMessage.hpp"

class transmitterctrl : public rtos::task<>
{
private:
	transmitter & trans;
	rtos::channel<IRMessage, 10> chan;
	void main();
public:
	transmitterctrl(char * name, transmitter & trans);
	void add(IRMessage m);
};

#endif //TRANSMITTERCTRL_HPP