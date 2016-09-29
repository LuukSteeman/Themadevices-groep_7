/// @file
#include "sam.h"
#include "infrared.hpp"
#include "hwlib.hpp"

/// Main function
//
/// The main function where the watchdog is being killed, the object IR from class infrared is being made and initialized. 
/// As long as the program lives, it checks for infrared input
/// 
/// All the variables are being defined at the top of their .cpp files. Add here your pinnumbers. Recommended is not to change these
int main(void){
	/// kill Watchdog
    //
    /// Killing the watchdog, so the program doesn't think it crashes
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	/// Creating infrared object
    //
    /// Created infrared object ir, which is directly initialized by init(); 
    /// infrared(int state); 
	infrared ir(1);
	ir.init();
    
    /// Infinite for loop
    //
    /// The infrared::drive function receives an integer value from the infrared::check function, which returns a bitpatron converted to a integervalue
    
    
	
    for(;;){
		ir.drive(ir.check());
	}

}