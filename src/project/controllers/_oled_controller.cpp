#include "oled_controller.hpp"

void oled_controller::main(){
    
    // oled.outstream1  << "\f"
    //             << "1" << "\n";   
    // oled.outstream2  << "\f"
    //             << "2" << "\n";
    // oled.outstream3  << "\f"
    //             << "3" << "\n";
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