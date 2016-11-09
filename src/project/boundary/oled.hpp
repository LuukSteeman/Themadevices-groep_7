#ifndef OLED_HPP
#define OLED_HPP

#include <hwlib.hpp>

/// Use the target as namespace... less typing
namespace target = hwlib::target;

namespace hwlib { 
   /// Create pin decorator
   class pin_fixed {
   public:    
      pin_fixed( pin_out & pin, bool v ){
         pin.set( v );
      } 
   };
};

/// OLED class
//
/// The class which makes it possible for us to easily access the OLED screen
class oled {
   target::pin_oc scl, sda;
   hwlib::i2c_bus_bit_banged_scl_sda i2c_bus;
   target::pin_out pin_gnd, pin_vcc;
   hwlib::pin_fixed pin_gnd_fixed, pin_vcc_fixed;
   
public:
   hwlib::glcd_oled_buffered oled_buffered;

   /// OLED()
   //
   /// The OLED Constructor, it needs no parameters, it just created an OLED-Object
   oled():
      scl( target::pins::sda ),
      sda( target::pins::scl ),
      i2c_bus( scl, sda ),
      pin_gnd( target::pins::d19 ),
      pin_vcc( target::pins::d18 ),
      pin_gnd_fixed( pin_gnd, 0 ),
      pin_vcc_fixed( pin_vcc, 1 ),
      oled_buffered( i2c_bus, 0x3c )
   {}   
   /// OLED::Flush()
   //
   /// Flush to the screen
   void flush(){
      oled_buffered.flush();
   }
};

#endif