#include "Damage.hpp"
#include "Player.hpp"
#include "applicationLogic/messageLogic.hpp"
#include "boundary/keypad.hpp"
#include "boundary/oled.hpp"
#include "boundary/transmitter.hpp"
#include "controllers/keypadHandler.hpp"
#include "controllers/oled_controller.hpp"
#include "controllers/shootCtrl.hpp"
#include "controllers/transferController.hpp"
#include "controllers/transmitterctrl.hpp"
#include "damageStorage.hpp"
#include "drawables/text.hpp"
#include "entity/Player.hpp"
#include "hitController.hpp"
#include "interface/gui.hpp"
#include "messageLogic.hpp"
#include "receiver.hpp"
#include "receiverHandler.hpp"
#include "receiverHandler.hpp"
#include "receiverListener.hpp"
#include "speakercontroller.hpp"
#include "transmitter.hpp"
#include "transmitterctrl.hpp"
#include <hwlib.hpp>
#include <rtos.hpp>

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

  oled oled_screen;
  oled_controller oled_control(oled_screen);

  text t((char*)"Hi", 1);
  t.draw(oled_screen);


  Receiver r(hwlib::target::pins::d12);
  ReceiverHandler rh(r);

  auto speak_pin = hwlib::target::pin_out(hwlib::target::pins::d52);
  auto speak = Speaker(speak_pin);
  auto speakctrl = Speakercontroller((char *)"speaker", speak);
  speakctrl.set_frequency(1500);
  Player player;

  Keypad pad;
  Transmitter trans;
  Transmitterctrl transctrl(trans);
  player.setWeapon(5);
  shootCtrl shoot((char *)"task for shooting", transctrl, player);
  pad.addKeypadListener(&shoot);
  KeypadHandler handler(pad);
  HitController h(speakctrl, d, r, player);
  X x;
  pad.addKeypadListener(&x);
  oled_screen.flush();
  rtos::run();
  return 0;
}