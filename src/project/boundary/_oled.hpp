#ifndef OLED_HPP
#define OLED_HPP

#include <hwlib.hpp>


namespace target = hwlib::target;

namespace hwlib { 
   class pin_fixed {
   public:    
      pin_fixed( pin_out & pin, bool v ){
         pin.set( v );
      } 
   };
};

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

#endif