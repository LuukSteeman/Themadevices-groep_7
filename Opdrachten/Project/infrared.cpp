/// @file
/// Infrared Library

#include "infrared.hpp"
#include "sam.h"
#include "hwlib.hpp"

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
	static char code[14];
	int ir_value = 0;
    auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);
    /// Check for input and process it
    //
    /// If there's an input on the pin, it checks 14 more times for an input on the pin. If the value is 1, it appends the array with a '1', if it's a 0, it 
    /// appends the array with a '0'. We're working with the RC-5 protocol, which means an input is ready in 1.778 milliseconds. A high value looks like '-|_' 
    /// and a low value look slike '_|-'. When the value switches up, it waits 3/4 of the time it takes to get ready.
	if((ir_pin.get() == true)){ // Start bit received
		for(int j = 0; j < 15; j++){
			if((ir_pin.get() == true)){
                hwlib::wait_ns(900'000);
                if(ir_pin.get() == true){
                    code[j] = '1';
                    hwlib::cout << code[j] << hwlib::endl;                  
                }
			}	
			else{
                hwlib::wait_ns(900'000);
                if(ir_pin.get() == false){
                    code[j] = '0';      
                    hwlib::cout << code[j] << hwlib::endl;         
                }
			}
            

            while(1){
                if((code[j] == '1') && (ir_pin.get() == false)){
                    hwlib::wait_ns(1'800'000);
                    break;
                }
                
                else if((code[j] == '0') && (ir_pin.get() == true)){
                    hwlib::wait_ns(1'800'000);
                    break;
                }
            }
		}

        /// Check the checksum
        //
        /// A proper explanation on how to handle the checksum

        for(int x = 0; x < 5; x++){
            if(code[(x+10)] != (code[x] ^ code[(x+5)])){
                break; // Not sure though
            }
        }   



        /// Convert array to integer value
        //
		/// Here we convert the array to an integer value, which makes it easier to pass as parameter and use in a switch statement. I chose 8192 as divider, because 2^13 =
        /// 8192. We also print this value as a simple test, if you get random codes, you probably use a remote which doesn't support the RC-5 protocol. Try using a older
        /// Philips remote.
		for(int k = 0; k < 14; k++){
			ir_value = ir_value + ((code[k] - '0') * (8192 / k));
		}
        
        hwlib::cout << hwlib::left << hwlib::setw( 5 ) << code << "  |  " << ir_value << "\n\n";
        
	}
	
    /// ir_value = 0 if there's no input
    //
    /// If the Arduino receives no input from the pin or remote, it returns a '0'. If you do press a button, make sure your infrared receiver is connected correctly
	else{
		for(int i = 0; i < 14; i++){
			code[i] = 0;
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