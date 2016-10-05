/// @file
/// Infrared Library

#include "infrared.hpp"
#include "sam.h"
#include "hwlib.hpp"
#include "IRMessage.hpp"

/// Get class parameters
//
/// Get the parameters which were given when creating the class
infrared::infrared(int state):
    state(state)
{}

/// Infrared::init()
//
/// Initialize infrared function by declaring the force lights and printing the code below, easy way to find out if the cout command and the connection between the car work
void infrared::init(){
	hwlib::cout << hwlib::left << hwlib::setw( 5 ) << "Initializing Infrared function | State: " << state << "\n";
}

/// Infrared::check(int pin) [RC-5 protocol]
//
/// The check() function checks for an input on the given pin. It creates a 14 character sized array. If there's an input on the pin, it checks 14 more times for an input
/// on the pin. If the value is 1, it appends the array with a '1', if it's a 0, it appends the array with a '0'. We're working with the RC-5 protocol, which means
/// an input is ready in 1.778 milliseconds. A high value looks like '-|_' and a low value look slike '_|-'. When the value switches up, it waits 3/4 of the time it
/// takes to get ready. We do this because of the delay between hitting the button on the remote and when it's available on the Arduino to work with. In the end we convert
/// the array into a integervalue, because it's hard to pass an array as parameter
int infrared::check(){
	short msg = 0;
	int ir_value = 0;
	
	int last_bit;
	
    auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);
    /// Check for input and process it
    //
    /// If there's an input on the pin, it checks 14 more times for an input on the pin. If the value is 1, it appends the array with a '1', if it's a 0, it 
    /// appends the array with a '0'. We're working with the RC-5 protocol, which means an input is ready in 1.778 milliseconds. A high value looks like '-|_' 
    /// and a low value look slike '_|-'. When the value switches up, it waits 3/4 of the time it takes to get ready.
	if((ir_pin.get() == true)){ // Start bit received
		msg = msg | (1<<15);
		hwlib::wait_ns(2'400'000);
		for(int j = 0; j < 15; j++){
			if((ir_pin.get() == true)){
                hwlib::wait_ns(900'000);
                if(ir_pin.get() == true){
					
					last_bit = 1;
                    msg = msg | (1<<(14-j));
                    hwlib::cout << msg << hwlib::endl;                  
                }
			}	
			else{
                hwlib::wait_ns(900'000);
                if(ir_pin.get() == false){
					last_bit = 0;
					msg = msg | (0<<(14-j));      
                    hwlib::cout << msg << hwlib::endl;         
                }
			}
            

            while(1){
                if((last_bit == 1) && (ir_pin.get() == false)){
                    hwlib::wait_ns(800'000);
                    break;
                }
                
                else if((last_bit == 0) && (ir_pin.get() == true)){
                    break;
                }
            }
		}

        IRMessage irm(msg);
        
        hwlib::cout << hwlib::left << hwlib::setw( 5 ) << " userId :  " << irm.getId() << ". message Data:" << irm.getData() << "\n\n";
        
	}
	
    /// ir_value = 0 if there's no input
    //
    /// If the Arduino receives no input from the pin or remote, it returns a '0'. If you do press a button, make sure your infrared receiver is connected correctly
	else{
		for(int i = 0; i < 16; i++){
			msg = msg | (1<<(15-i));
		}
		ir_value = 0;
	}
	
	return ir_value;
}

/// Infared::drive(int ir_value)
//
/// The drive function receives a ir_value as parameter, which resembles the button you pressed on the remote. It casts the ir_value to a command from the wheel library
void infrared::drive(int ir_value){
    /// Create wheels object
    //
    /// Creating and inializing a wheels object, so we can use the library. Values are as follow
    /// Wheels(int state);
//    game g(1);
//	g.init();
    /// Casting command
    
}