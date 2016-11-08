#include <hwlib.hpp>
#include "transmitterctrl.hpp"
#include "transmitter.hpp"
#include <rtos.hpp>
#include "applicationLogic/messageLogic.hpp"
#include "controllers/shootCtrl.hpp"
#include "boundary/transmitter.hpp"
#include "controllers/transmitterctrl.hpp"
#include "boundary/keypad.hpp"
#include "controllers/keypadHandler.hpp"


int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  Keypad pad;
  Transmitter trans;
  Transmitterctrl transctrl(trans);
  shootCtrl shoot((char*)"task for shooting", transctrl);
  pad.addKeypadListener(&shoot);
  KeypadHandler handler(pad);

  rtos::run();
  return 0;
}