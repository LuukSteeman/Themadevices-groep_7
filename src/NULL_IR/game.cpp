#include "game.hpp"
#include "sam.h"
#include "hwlib.hpp"

auto pin_d7 = hwlib::target::pins::d7;
auto pin_d6 = hwlib::target::pins::d6;
auto pin_d5 = hwlib::target::pins::d5;
auto pin_d4 = hwlib::target::pins::d4;

//// game
/// Get class parameters
//
/// Get the parameters which were given when creating the class
game::game(int state):
    state(state)
{}

/// game::int()
//
/// Initialize the game class
void game::init(){
	hwlib::cout << hwlib::left << hwlib::setw( 5 ) << "Initializing Game function | State: " << state << "\n";
    
}