//copyright: sqrtroot

//Check if we're compiling for arm or for pc
//Then include he correct libraries
#ifdef __arm__
    #include "hwlib.hpp"
#else
    #include <iostream>
    #include <string>
#endif

#include "string.h"
template <typename T>
void print(T in){
    #ifdef __arm__
        hwlib::cout<<in;
    #else
        std::cout<<in;
    #endif
}

void setup()
    {
        //check if we're compiling for arm and need to call some hw libs first
        #ifdef __arm__
            // kill the watchdog
            WDT->WDT_MR = WDT_MR_WDDIS;
            // wait for the PC console to start
            hwlib::wait_ms(500);
        #endif // __CC_ARM
    };

int main()
{
    setup();
    #ifdef __arm__
        char const* printString = "Hallo\n";
        String<20> a((char *)printString);
    #else
        std::string printString("ABCDEFG\n");
        String<20> a(printString);
    #endif
        print(a.c_str());
    return 0;
}