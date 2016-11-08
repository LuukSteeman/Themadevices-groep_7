#include <hwlib.hpp>
#include <rtos.hpp>
#include "drawables/text.hpp"
#include "boundary/oled.hpp"
#include "controllers/oled_controller.hpp"

class BasicMain : public rtos::task<>{
  private:
    void main(){
      oled oled_screen;
      oled_controller oled_control((char*)"OLED Controller", oled_screen);

      text t("Hi");

      oled_control.add(t);

      while(1){
        //of hier
      }
    }
}

int main(){
  WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);
  
  BasicMain bscmn;
  rtos::run();
}