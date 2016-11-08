#include <hwlib.hpp>
#include "transmitterctrl.hpp"
#include "transmitter.hpp"
#include <rtos.hpp>
#include "receiver.hpp"
#include "receiverHandler.hpp"
#include "receiverListener.hpp"
#include "speakercontroller.hpp"
#include "messageLogic.hpp"
#include "damageStorage.hpp"
#include "Damage.hpp"
#include "controllers/transferController.hpp"
#include "hitController.hpp"
#include "Player.hpp"
#include "receiverHandler.hpp"

class X :public ReceiverListener{
  public:
    void msgReceived(MessageLogic msg){
      hwlib::cout << "i\n";
    }
};

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);
  DamageStorage d;

  Receiver r(hwlib::target::pins::d12);
  ReceiverHandler rh(r);
  
  X x;
  r.addReceiverListener(&x);

  auto speak_pin = hwlib::target::pin_out(hwlib::target::pins::d52);
  auto speak = Speaker(speak_pin);
  auto speakctrl = Speakercontroller((char *)"speaker", speak);
  speakctrl.set_frequency(1500);
  Player p;
  HitController h(speakctrl, d, r, p);
  
  rtos::run();
  return 0;
}