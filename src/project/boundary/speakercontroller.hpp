#include "speaker.hpp"

#ifndef SPEAKERCONTROLLER_HPP
#define SPEAKERCONTROLLER_HPP

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

	//The add() function is the interface other tasks can use to interact with this task.
	void add(int hit);
};

#endif //SPEAKERCONTROLLER_HPP