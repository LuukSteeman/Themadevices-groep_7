@file

#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/text.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"


class Main : rtos::task<> {
private:
    /// Create oled_controller and oled objects
    //
    /// These objects will be used for writing the GUI objects to a channel and to write them to the OLED screen

    oled_controller & oled_control;
    oled & oled_screen;


    void main() {


        int i = 0; 
        /// Create 3 text-objects, the parameters contain the text to be written on the screen, the number is the location on the screen
        text s((char *)i, 1);
        text t((char *)"2", 2);
        text u((char *)"3", 3);

        /// Add text-objects to the oled_channel, this contains all objects to be written to the screen, when they've been read, they're deleted from the channel
        oled_control.add(&s);
        oled_control.add(&t);
        oled_control.add(&u);


        hwlib::cout << "started main controller\n";

        /// The code insde this while-loop will be run until the program is being terminated
        while (1) {

            i++;

            /// Update the text-object "s", the text is changed in "i", which we currently use as a timer
            s.update((char*) i);

            /// Add the objects to the channel again, because they were deleted when we read them
            oled_control.add(&s);
            oled_control.add(&t);
            oled_control.add(&u);

            /// Wait 1 second
            sleep(1 * rtos::s);

            /// Write the buffered objects to the screen
            oled_control.flush();

        }
    };

public:
    /// De Main Constructor
    //
    /// Give the task a name, an oled_controller and an oled
    Main(oled_controller & oled_control, oled & oled_screen) : 
        task((char *)"Maintask"), 
        oled_control(oled_control),
        oled_screen(oled_screen)
    {};
};


/// Main function
//
/// The main function which will initialize the program
int main()
{
    /// Kil the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    /// Wait 500ms
    hwlib::wait_ms(500);

    /// Create an oled_control object
    oled_controller oled_control(oled_screen);

    /// Create an oled object
    oled oled_screen = oled();

    /// Create the main object, give it the oled_controller and oled objects
    Main m(oled_control, oled_screen);

    /// Run the RTOS task, all tasks below this functioncall won't be executed
    rtos::run();

    /// Testing whether the RTOS task works
    hwlib::cout << "Written";
    return 0;
}