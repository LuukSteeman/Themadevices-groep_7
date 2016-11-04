#include <hwlib.hpp>
#include <rtos.hpp>

#include "boundary/receiver.hpp"
#include "controllers/receiverHandler.hpp"
#include "interfaces/receiverListener.hpp"
#include "boundary/speakercontroller.hpp"
#include "applicationLogic/messageLogic.hpp"

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