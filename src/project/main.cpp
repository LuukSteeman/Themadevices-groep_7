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
#include "Keypad.hpp"
#include "keypadHandler.hpp"
#include "PlayerID.hpp"

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);


  Player pyer;
  PlayerID id;

  DamageStorage ds;

  TransferController transferctrl(ds);

  Keypad pad;
  KeypadHandler handle(pad);
  SetupController sctrl(pyer, id, transferctrl);

  Receiver receive(hwlib::target::pins::d12);
  ReceiverHandler rhandle(receive);


  receive.addReceiverListener(&sctrl);
  pad.addKeypadListener(&sctrl);


  rtos::run();
  return 0;
}