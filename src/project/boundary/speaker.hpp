///@file
///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#ifndef SPEAKER_HPP
#define SPEAKER_HPP

#include "hwlib.hpp"
#include "sam.h"
#include "rtos.hpp"

///Speakerclass
//
///The speaker class serves as a boundary I/O object to produce a sound
///of a set frequency and variable time when called.
///While intended for speakers, this class can also be used for
///other devices with a single input which require a modulated output.

class Speaker
{
private:
    ///lsp is a reference to the pin to which the output is send.
    hwlib::pin_out & lsp;

public:

    ///When making a speaker object, provide an output pin to initialize the object.
    Speaker(hwlib::pin_out & lsp);

    ///set() sets the output of the lsp pin
    ///@param 1 sets the output high, 0 sets it low.
    void set(int m);
};

#endif //SPEAKER_HPP
