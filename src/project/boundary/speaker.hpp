///@file

#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "hwlib.hpp"
#include "sam.h"
#include "rtos.hpp"

///Speakerclass
//
///The speaker class is an implementation of hwlib::pin_out. It uses similiar code to the d2_36kHz class to set pin d2 to an adjustable output.

class Speaker
{
private:
	hwlib::pin_out & lsp;
	int frequency = 0;
public:

	///The speaker constructor is empty as it's hard coded on pin d2.
	Speaker(hwlib::pin_out & lsp);

	///Using the set_frequency() function sets the PWM output on the frequency you give as parameter.
	///speaker.set_frequency(1500) for instance, sets the frequency on 1500Hz.
	///@param an integer to determine the frequency
	void set_frequency(int freq);


	///The play() function produces a signal of the set frequency on the designated pin.
	///@param note_length determines the length of the sound in ms.
	void play();
};

#endif //SPEAKER_HPP