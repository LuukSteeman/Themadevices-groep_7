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

#ifndef SPEAKERTASK_HPP
#define SPEAKERTASK_HPP

///Speakercontroller
//
///The speakertask is an implementation of the rtos::task template.
///This task is the controller of the speaker.

class Speakercontroller : public rtos::task<>
{
private:
	//The Speakercontroller has a reference to its speaker.
	Speaker & speak;

	//The main function of this controllertask checks if there's an object in the channel.
	//If so, it will use the value of the integer to determine the length of the sound.
	//It will set the speaker pin high for the duration of the integer in milliseconds.
	void main();

	//The rtos::channel is used as a concurrency mechanism with other tasks.
	rtos::channel< int, 1 > hits;
public:

	//The Speakercontroller constructor requires a name and a reference to the speaker it's going to control.
	//It will initialize its own channel.
	Speakercontroller(char * name, Speaker & speak) : task(name), speak(speak), hits(this, "hitschannel"){};

	//The add() function is the interface other tasks can use to send messages to this task.
	void add(int hit);
};

#endif //SPEAKERTASK_HPP