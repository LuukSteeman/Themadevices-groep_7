#include "hwlib/hwlib.hpp"
// #include <rtos.hpp>

namespace target = hwlib::target;

namespace hwlib { 
   class pin_fixed {
   public:    
      pin_fixed( pin_out & pin, bool v ){
         pin.set( v );
      } 
   };
};

   // The OLED display is connected in a very funny way:
   // the I2C pins are reversed, and two GPIO pins are
   // (mis-) used as ground and power for the display.
   // This works, and makes it very easy to connect the LCD,
   // but don't take this as an advice to connect peripherals is this way
   // unless you know very well what you are doing.
class oled_buffered_d18_d21 {
   target::pin_oc scl, sda;
   hwlib::i2c_bus_bit_banged_scl_sda i2c_bus;
   target::pin_out pin_gnd, pin_vcc;
   hwlib::pin_fixed pin_gnd_fixed, pin_vcc_fixed;
   
public:
   hwlib::glcd_oled_buffered oled;

   oled_buffered_d18_d21():
      scl( target::pins::sda ),
      sda( target::pins::scl ),
      i2c_bus( scl, sda ),
      pin_gnd( target::pins::d19 ),
      pin_vcc( target::pins::d18 ),
      pin_gnd_fixed( pin_gnd, 0 ),
      pin_vcc_fixed( pin_vcc, 1 ),
      oled( i2c_bus, 0x3c )
   {}   
};


int main(){
	oled_buffered_d18_d21 oled_class;
    auto hw = oled_buffered_d18_d21();
    auto & oled = hw.oled;


    auto window1 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 0 ),
        hwlib::location( 96, 32));
    auto window2 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 32 ),
        hwlib::location( 96, 32));
    auto window3 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 64 ),
        hwlib::location( 32, 64));
     

    auto font_small = hwlib::font_default_8x8();
    auto font_big = hwlib::font_default_16x16();


    static auto outstream1 = hwlib::window_ostream( window1, font_big );
	std::cout << typeid(outstream1).name() << '\n';
}