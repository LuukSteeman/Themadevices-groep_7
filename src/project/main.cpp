#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/string.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class Main : public rtos::task<>{
  private:
    oled oled_screen;
    oled_controller oled_control((char*)"OLED Controller", oled_screen);

    string s((char*)"Hi");
    void main(){

      oled_control.add(s);

      while(1){
        //of hier
      }
    }

  public:
    Main(oled_controller & oled_control, char *name) : 
      oled_control(oled_control), task(name)
    {};

}

int main(){
  WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);
  
  auto oled_control = oled_controller((char*)"Controller");
  auto Maintask = Main(&oled_control, "Testmaintask");
  rtos::run();
}