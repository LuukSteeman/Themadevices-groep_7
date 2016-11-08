/*
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:29: warning: argument 'Provide' of command @param is not found in the argument list of Speakercontroller::Speakercontroller(char *name, Speaker &speak)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:33: warning: The following parameters of Speakercontroller::Speakercontroller(char *name, Speaker &speak) are not documented:
  parameter 'speak'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:43: warning: argument 'the' of command @param is not found in the argument list of Speakercontroller::add(int hit)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:45: warning: The following parameters of Speakercontroller::add(int hit) are not documented:
  parameter 'hit'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:39: warning: argument 'Note_length' of command @param is not found in the argument list of Speakercontroller::play(int note_length)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:41: warning: The following parameters of Speakercontroller::play(int note_length) are not documented:
  parameter 'note_length'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:35: warning: argument 'provide' of command @param is not found in the argument list of Speakercontroller::set_frequency(int freq)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/boundary/speakercontroller.hpp:37: warning: The following parameters of Speakercontroller::set_frequency(int freq) are not documented:
  parameter 'freq'

*/

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
	///The Speakercontroller has a reference to its speaker.
	Speaker & speak;

	///The main function of this controllertask checks if there's an object in the channel.
	///If so, it will use the value of the integer to determine the length of the sound.
	///It will set the speaker pin high for the duration of the integer in milliseconds.
	void main();

	///The rtos::channel is used as a concurrency mechanism with other tasks.
	rtos::channel< int, 1 > hits;

	///Time is calculated when the set_frequency() function is called. It calculates the time of a single period in microseconds.
	int time;
public:

	///The Speakercontroller constructor requires a name and a reference to the speaker it's going to control.
	///It will initialize its own channel.
	///@param name gives the task a name for debugging.
	///@param Provide a speaker so the controller knows what pin to call.
	Speakercontroller(char * name, Speaker & speak) : task(name), speak(speak), hits(this, "hitschannel"){};

	///set_frequency() calculates the time of a single period in microseconds, which is used by the play() function to produce a sound of the set frequency.
	///@param provide a frequency in Hz.
	void set_frequency(int freq);

	///Play sets the output on the pin high and low based on the time calculated by set_frequency().
	///@param Note_length determines the how long the sound will play.
	void play(int note_length);

	///The add() function is the interface other tasks can use to interact with this task.
	///@param the hit is an integer which is used to determine the notelength for hte play() function.
	void add(int hit);
};

#endif //SPEAKERCONTROLLER_HPP