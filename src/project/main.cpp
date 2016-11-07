#include <hwlib.hpp>
#include "IRMessage.hpp"
#include "transmitterctrl.hpp"
#include "IRMessage.hpp"
#include "transmitter.hpp"
#include <rtos.hpp>
#include "receiver.hpp"
#include "receiverHandler"
#include "receiverListener"
#include "Speakercontroller"
#include "messageLogic"
#include "damageStorage"
#include "damage"

class Maintask : public rtos::task<>
{
private:
    Transmitterctrl & transctrl;
    IRMessage msg;
    void main()
    {
    	while(1)
    	{
	        transctrl.add(msg);
	        sleep(2 * rtos::s);
	    }
    }
public:
    Maintask(Transmitterctrl & transctrl, IRMessage msg) :
    transctrl(transctrl),
    msg(msg)
    {}

class x : public ReceiverListener
{
public:
  void msgReceived(MessageLogic msg)
  {
    hwlib::cout << msg.getData();
  }
};

class Main : rtos::task<>
{
  Speakercontroller &spctrl;

private:
  void main()
  {
    while (1)
    {
      // sleep(10 * rtos::s);
      spctrl.add(700);
      sleep(2 * rtos::s);
      spctrl.add(200);
      sleep(2 * rtos::s);
    };
  };

public:
  Main(Speakercontroller &spctrl, char *name) : task(name),
                                                spctrl(spctrl){};
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    Transmitter trans;
    Transmitterctrl transctrl((char *) "Transmittercontroller and task", trans);
    IRMessage message(10,5);
    Maintask main(transctrl, message);
    DamageStorage d;
    d.addDamage(10, 3);
    d.addDamage(5, 4);
    d.addDamage(6, 5);
    for (int i=0;i<3;i++){
        Damage damageEntity = d.getDamage(i);
        hwlib::cout << damageEntity.getDamageAmount();
        hwlib::cout << damageEntity.getPlayerID();
    }

  Receiver r(hwlib::target::pins::d12);
  ReceiverHandler rh(r);

  x X;
  r.addReceiverListener(&X);

  auto speak_pin = hwlib::target::pin_out(hwlib::target::pins::d52);
  auto speak = Speaker(speak_pin);
  auto speakctrl = Speakercontroller((char *)"speaker", speak);
  speakctrl.set_frequency(1500);
  auto Maintask = Main(speakctrl, (char *)"Testmaintask");

  rtos::run();

  return 0;
}