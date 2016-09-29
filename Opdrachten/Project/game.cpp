#include "game.hpp"
#include "sam.h"
#include "hwlib.hpp"
#include "lights.hpp"

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
	hwlib::cout << hwlib::left << hwlib::setw( 5 ) << "Initializing Wheel function | State: " << state << "\n";
    
}

/// game::forward(int force);
//
/// If the force parameter is '2', go full speed forwards. If force is '1', go full speed for 100 milliseconds and then disable the motors for 50 milliseconds, so it will
/// go on about 80% of the power. If force is '0', go full speed for 100 milliseconds and then disable the motors for 50 milliseconds, so it will go on about 66% 
/// of the power.
void game::forward(int force){
    lights l(1);
    
	if(force == 2){
        l.switch_lights(6);
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
	}
    
    else if(force == 1){
        l.switch_lights(6);
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
	}
    
	else{
		
        l.switch_lights(6);
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
		
		hwlib::wait_ms(100);
        
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
		hwlib::target::pin_out(pin_d5).set(0);// Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off

		hwlib::wait_ms(50);
		
	}
	
}

/// game::left(int force);
//
/// If the force parameter is '2', the left wheel goes backwards and the right one goes forward, which makes the rotation twice as fast.
/// If force is '1', the right wheel goes full speed until you stop it. If force is '0', you'll have a small 75 degree rotation. When 
/// the force is '1' or '2', the blinking lights are enables. 
void game::left(int force){
    lights l(1);
    
	if(force == 2){ 
		hwlib::target::pin_out(pin_d7).set(1); // Set Wheel Left Back -> on
		hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
	}
    
    else if(force == 1){
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
        l.switch_lights(4);
    }
	
	else{
        for(int i = 0; i < 10; i++){
            hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
            hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
            hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
            hwlib::target::pin_out(pin_d4).set(1); // Set Wheel Right Front -> on
                
            hwlib::wait_ms(50);
            
            hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
            hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
            hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
            hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
                
            hwlib::wait_ms(20);
        }
	}
}

/// game::right(int force);
//
/// If the force parameter is '2', the left wheel goes backwards and the right one goes forward, which makes the rotation twice as fast.
/// If force is '1', the right wheel goes full speed until you stop it. If force is '0', you'll have a small 75 degree rotation. When 
/// the force is '1' or '2', the blinking lights are enables. 

void game::right(int force){
    lights l(1);
    
	if(force == 2){ 
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
		hwlib::target::pin_out(pin_d5).set(1); // Set Wheel Right Back -> on
		hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
	}
	
	else if(force == 1){
		hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
		hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
		hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
		hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
        l.switch_lights(5);
	}
    
    else{
        for(int i = 0; i < 10; i++){
            hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
            hwlib::target::pin_out(pin_d6).set(1); // Set Wheel Left Front -> on
            hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
            hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
                
            hwlib::wait_ms(50);
                
            hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
            hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
            hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
            hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
            
            hwlib::wait_ms(20);
        }
        
    }
}

/// game::backwards();
//
/// This function makes the car backup until you stop it

void game::backward(){
    lights l(1);
    
    hwlib::target::pin_out(pin_d7).set(1); // Set Wheel Left Back -> on
    hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
    hwlib::target::pin_out(pin_d5).set(1); // Set Wheel Right Back -> on
    hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
	l.switch_lights(8);
}


/// game::off();
//
/// This function makes the car turn off, disabling the game and lights

void game::off(){	
    lights l(1);
    
    hwlib::target::pin_out(pin_d7).set(0); // Set Wheel Left Back -> off
    hwlib::target::pin_out(pin_d6).set(0); // Set Wheel Left Front -> off
    hwlib::target::pin_out(pin_d5).set(0); // Set Wheel Right Back -> off
    hwlib::target::pin_out(pin_d4).set(0); // Set Wheel Right Front -> off
	l.switch_lights(0);
}

/// game::lights(int light);
//
/// The function which controls the lights. 
/// Is the parameter '0'? Turn off all the lights
/// Is the parameter '1'? Enable all lights
/// Is the parameter '2'? Showoff the lights, causing it to blink all the lights once
/// Is the parameter '3'? Enable main lights
/// Is the parameter '4'? Blink left directional lights
/// Is the parameter '5'? Blink right directional lights
/// Is the parameter '6'? Toggle headlights
/// Is the parameter '7'? Toggle backlights
/// Is the parameter '8'? Blink backlights

