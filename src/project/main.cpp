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
#include "Player.hpp"
#include "keypad.hpp"
#include "keypadHandler.hpp"
#include "playerID.hpp"
#include "hitController.hpp"
#include "Player.hpp"
#include "receiverHandler.hpp"
#include "applicationLogic/messageLogic.hpp"
#include "controllers/shootCtrl.hpp"
#include "boundary/transmitter.hpp"
#include "controllers/transmitterctrl.hpp"
#include "boundary/keypad.hpp"
#include "controllers/keypadHandler.hpp"
#include "entity/Player.hpp"

class X : public KeypadListener
{
public:
  void keyPressed(char key)
  {
    if (key == 'A')
    {
      rtos::display_statistics();
    }
    else if (key == 'B')
    {
      rtos::do_statistics_clear();
    }
  }
};

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);
  DamageStorage d;

  auto speak_pin = hwlib::target::pin_out(hwlib::target::pins::d52);
  auto speak = Speaker(speak_pin);
  auto speakctrl = Speakercontroller((char *)"speaker", speak);
  speakctrl.set_frequency(1500);

  Player player;
  PlayerID id;

  DamageStorage ds;

  TransferController transferctrl(ds);

  Keypad pad;
  KeypadHandler handle(pad);
  rtos::flag startFlag(nullptr, "StartFlag");
  SetupController sctrl(player, id, transferctrl, startFlag);

  Receiver receive(hwlib::target::pins::d12);
  ReceiverHandler rhandle(receive);

  receive.addReceiverListener(&sctrl);
  pad.addKeypadListener(&sctrl);

  Transmitter trans;
  Transmitterctrl transctrl(trans);
  player.setWeapon(5);
  shootCtrl shoot((char *)"task for shooting", transctrl, player, startFlag);
  pad.addKeypadListener(&shoot);
  KeypadHandler handler(pad);
  HitController h(speakctrl, d, receive, player, startFlag);
  X x;
  pad.addKeypadListener(&x);
  rtos::run();
  return 0;
}