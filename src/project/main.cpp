#include <hwlib.hpp>
#include <rtos.hpp>

class BasicMain : public rtos::task<>{
  private:
    void main(){
      //doe hier iets.

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