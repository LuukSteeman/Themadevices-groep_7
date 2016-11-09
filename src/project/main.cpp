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

class Maintask : public rtos::task<>
{
private:
  Transmitterctrl &transctrl;
  MessageLogic msg;
  void main()
  {
    while (1)
    {
      transctrl.add(msg);
      sleep(2 * rtos::s);
    }
  };

public:
  Maintask(Transmitterctrl &transctrl, MessageLogic msg) : transctrl(transctrl),
                                                           msg(msg)
  {
  }
};
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
private:
  void main()
  {
    DamageStorage ds;

    ds.addDamage(10, 3);
    ds.addDamage(5, 4);
    ds.addDamage(6, 5);

    TransferController t(ds);
    while (1)
    {
      t.run(this);
    }
  }
};

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);
  Transmitter trans;
  Transmitterctrl transctrl((char *)"Transmittercontroller and task", trans);
  MessageLogic message(10, 5);
  Maintask main(transctrl, message);
  DamageStorage d;
  d.addDamage(10, 3);
  d.addDamage(5, 4);
  d.addDamage(6, 5);
  for (int i = 0; i < 3; i++)
  {
    DamageEntity damageEntity = d.getDamage(i);
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
  auto Maintask = Main();

  rtos::run();
  return 0;
}