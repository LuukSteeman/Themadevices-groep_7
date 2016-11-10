#include <hwlib.hpp>
#include <rtos.hpp> 
#include "text.hpp"
#include "oled.hpp"
#include "oled_controller.hpp"
#include "transmitterctrl.hpp"
#include "transmitter.hpp"
#include "receiver.hpp"
#include "receiverHandler.hpp"
#include "receiverListener.hpp"
#include "speakercontroller.hpp"
#include "messageLogic.hpp"
#include "damageStorage.hpp"
#include "Damage.hpp"
#include "transferController.hpp"

class Maintask : public rtos::task<>
{
private:

  Transmitterctrl &transctrl;
  MessageLogic msg;
  oled_controller & oled_control;
  oled & oled_screen;
  void main() {
    int i = 0; 
    /// Create 3 text-objects, the parameters contain the text to be written on the screen, the number is the location on the screen
    text s((char *)i, 1);
    text t((char *)"2", 2);
    text u((char *)"3", 3);

    /// Add text-objects to the oled_channel, this contains all objects to be written to the screen, when they've been read, they're deleted from the channel
    oled_control.add(&s);
    oled_control.add(&t);
    oled_control.add(&u);


    hwlib::cout << "started main controller\n";

    while (1)
    {
      i++;

      /// Update the text-object "s", the text is changed in "i", which we currently use as a timer
      s.update((char*) i);

      /// Add the objects to the channel again, because they were deleted when we read them
      oled_control.add(&s);
      oled_control.add(&t);
      oled_control.add(&u);

      /// Wait 1 second
      sleep(1 * rtos::s);

      /// Write the buffered objects to the screen
      oled_control.flush();

      transctrl.add(msg);
      sleep(2 * rtos::s);
    }
  };

public:
  Maintask(Transmitterctrl &transctrl, MessageLogic msg, oled_controller & oled_control, oled & oled_screen) : 
      task((char *)"Maintask"), 
      transctrl(transctrl),
      msg(msg),
      oled_control(oled_control),
      oled_screen(oled_screen)
  {}

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


  /// Create an oled object
  oled oled_screen = oled();

  /// Create an oled_control object
  oled_controller oled_control(oled_screen);

  Transmitter trans;
  Transmitterctrl transctrl((char *)"Transmittercontroller and task", trans);
  MessageLogic message(10, 5);
  Maintask main(transctrl, message, oled_control, oled_screen);
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