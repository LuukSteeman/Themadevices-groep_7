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
#include "entity/Player.hpp"



int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  Keypad pad;
  Transmitter trans;
  Transmitterctrl transctrl(trans);
  Player player;
  player.setWeapon(5);
  shootCtrl shoot((char*)"task for shooting", transctrl, player);
  pad.addKeypadListener(&shoot);
  KeypadHandler handler(pad);

  rtos::run();
  return 0;
}