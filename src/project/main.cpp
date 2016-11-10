#include <hwlib.hpp>
#include "transmitterctrl.hpp"
#include "transmitter.hpp"
#include <rtos.hpp>
#include "receiver.hpp"
#include "receiverHandler.hpp"
#include "receiverListener.hpp"
#include "speakercontroller.hpp"
#include "setupController.hpp"
#include "messageLogic.hpp"
#include "damageStorage.hpp"
#include "Damage.hpp"
#include "controllers/transferController.hpp"
#include "setupController.hpp"
#include "Player.hpp"
#include "keypad.hpp"
#include "keypadHandler.hpp"
#include "playerID.hpp"
#include "gamemasterctrl.hpp"

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  Keypad pad;
  KeypadHandler handle(pad);
  Transmitter transmitter;
  Transmitterctrl transmitterctrl(transmitter);

  GamemasterCtrl gamemasterctrl(transmitterctrl, (char *)"Gamemaster task");

  pad.addKeypadListener(&gamemasterctrl);


  rtos::run();
  return 0;
}