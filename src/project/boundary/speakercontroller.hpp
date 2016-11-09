///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman
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

    ///Time is calculated when the set_frequency() function is called.
    ///It calculates the time of a single period in microseconds.
    int time;
public:

    ///The Speakercontroller constructor requires a name
    ///and a reference to the speaker it's going to control.
    ///It will initialize its own channel.
    ///@param name gives the task a name for debugging.
    ///@param Provide a speaker so the controller
    ///knows what pin to call.
    Speakercontroller(char * name, Speaker & speak) : task(name), speak(speak), hits(this, "hitschannel"){};

    ///set_frequency() calculates the time of a single period in microseconds, 
    ///which is used by the play() function to produce a sound of the set frequency.
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
