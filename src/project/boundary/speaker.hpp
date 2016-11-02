///@file

#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "hwlib.hpp"
#include "sam.h"
#include "rtos.hpp"

///Speakerclass
//
///The speaker class is an implementation of hwlib::pin_out. It uses similiar code to the d2_36kHz class to set pin d2 to an adjustable output.

class Speaker : public hwlib::pin_out
{
private:

	int frequency = 0;
public:

	//The speaker constructor is empty as it's hard coded on pin d2.
	Speaker();

	//Using the set_frequency() function sets the PWM output on the frequency you give as parameter.
	// speaker.set_frequency(1500) for instance, sets the frequency on 1500Hz.
	void set_frequency(int frequency);

	//The set function is used to start and stop the output.
	//set(0) will stop the pin from providing an output while set(1) will start the output.
	void set( bool b ) override;
};

#endif //SPEAKER_HPP