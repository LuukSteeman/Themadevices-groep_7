#include <hwlib.hpp>
#include <rtos.hpp>
#include "keypadHandler.hpp"
#include "gamemasterctrl.hpp"
#include "messageLogic.hpp"
#include "transmitter.hpp"
#include "transmitterctrl.hpp"
#include "keypad.hpp"

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  Keypad pad;
  KeypadHandler handle(pad);

  Transmitter transmitter;
  Transmitterctrl transmitterctrl(transmitter);

  Gamemasterctrl gamemasterctrl(transmitterctrl);
  pad.addKeypadListener(&gamemasterctrl);

  rtos::run();

  return 0;
}