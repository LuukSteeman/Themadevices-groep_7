/// @file
#include "infrared.hpp"

class Main: rtos::task<>{
    private:
    	infrared ir;
        void Main(){
				sleep(1 * rtos::s);
				while(1){
				 sleep(1 * rtos::s);
				};
        };
    public:
        Main(infrared ir, char * name):
        task(name),
        ir(ir)
        {
        	ir.init();
        };
};

/// Main function
//
/// The main function where the watchdog is being killed, the object IR from class infrared is being made and initialized. 
/// As long as the program lives, it checks for infrared input
/// 
/// All the variables are being defined at the top of their .cpp files. Add here your pinnumbers. Recommended is not to change these
int main(){
	/// kill Watchdog
    //
    /// Killing the watchdog, so the program doesn't think it crashes
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	hwlib::wait_ms(500);
	/// Creating infrared object
    //
    /// Created infrared object ir, which is directly initialized by init(); 
    /// infrared(int state); 

	auto y = infrared((1), (char *) "Infared Receiver");
	auto x = Main(y, (char *) "main");
    
    /// Infinite for loop
    //
    /// The infrared::drive function receives an integer value from the infrared::check function, which returns a bitpatron converted to a integervalue
    
    rtos::run();

    return 0;
}