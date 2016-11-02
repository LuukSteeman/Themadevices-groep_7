/// @file
#ifndef IRRECEIVER_HPP
#define IRRECEIVER_HPP

#include "IRMessage.hpp"
#include "hwlib.hpp"
#include "rtos.hpp"

class IRReceiver : public rtos::task<>
{
  private:
  	IRMessage im;
  public:
    void detect();
    void main();
	IRReceiver(char * taskName):task(taskName),im(){};
};

#endif //IRRECEIVER_HPP