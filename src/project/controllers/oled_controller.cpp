#include "oled_controller.hpp"


void OLED_Controller::init(int health){
    oled_buffered_d18_d21 oled_class;
    auto hw     = oled_buffered_d18_d21();
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


    auto outstream1 = hwlib::window_ostream( window1, font_big );
    auto outstream2 = hwlib::window_ostream( window2, font_big );
    auto outstream3 = hwlib::window_ostream( window3, font_small );
   
    outstream1 << "\f"
                    << "Out1";
    outstream2 << "\f"
                    << "Out2";
    outstream3 << "\f"
                    << "Out3";

    oled.flush();
      
    // for(;;){
    //    hwlib::wait_ms(100);
    //    // d2 << "\f" << ++n;
    //    oled.flush();
    // }      
}



// void OLED_Controller::count_down(auto &oled, int N){
//     for(int i = 0; i < N; i++){
//         auto w1 = hwlib::window_part( 
//             oled, 
//             hwlib::location( 0, 0 ),
//             hwlib::location( 128, 32));
//         auto w2 = hwlib::window_part( 
//             oled, 
//             hwlib::location( 0, 32 ),
//             hwlib::location( 128, 32));
     
//         auto f1 = hwlib::font_default_8x8();
//         auto d1 = hwlib::window_ostream( w1, f1 );

//         auto f2 = hwlib::font_default_16x16();
//         auto d2 = hwlib::window_ostream( w2, f2 );
          
//         d1 << "\f"
//             << "Levens";   
//         d2 << "\f"
//             << i << "\n";

//         oled.flush();

//         hwlib::wait_ms(100);
//     }
// }