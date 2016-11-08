#include <hwlib.hpp>
#include <rtos.hpp>
#include "applicationLogic/messageLogic.hpp"
#include "controllers/shootCtrl.hpp"
#include "boundary/transmitter.hpp"
#include "controllers/transmitterctrl.hpp"

class Main : rtos::task<>
{
  shootCtrl & shoot;

private:
  void main()
  {
    while (1)
    {
      // sleep(10 * rtos::s);
      shoot.keyPressed('*');
      sleep(2 * rtos::s);
    }
  }

public:
  Main(shootCtrl &shoot, char *name) : task(name),
                                                shoot(shoot){};
};

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  Transmitter trans;
  Transmitterctrl transctrl(trans);
  shootCtrl shoot((char*)"task for shooting", transctrl);
  rtos::run();

  return 0;
}