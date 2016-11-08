#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/string.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class Main : public rtos::task<>{
  private:
    oled_controller & oled_control;
    char ding;
    string s;
    void main(){
      while(1){
            oled_control.add(s);
            sleep(1 * rtos::s);
      }
    }

  public:
    Main(oled_controller & oled_control, char *name) : 
    task(name),
    oled_control(oled_control)
    {
      ding = 'o';
      s = string(&ding);
    }

};

int main(){
  WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);


  oled oled_screen;
  auto oled_control = oled_controller((char*)"Controller", oled_screen);
  auto Maintask = Main(oled_control, (char*)"Testmaintask");
  rtos::run();
}