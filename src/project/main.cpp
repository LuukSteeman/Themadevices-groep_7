#include "boundary/speakercontroller.hpp"
#include "hwlib.hpp"
#include "rtos.hpp"

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


int main (void)
{
	WDT->WDT_MR = WDT_MR_WDDIS;

	hwlib::wait_ms(500);
	
  auto speak_pin = hwlib::target::pin_out(hwlib::target::pins::d52);
	auto speak = Speaker(speak_pin);
	auto speakctrl = Speakercontroller((char *) "speaker", speak);
  speakctrl.set_frequency(1500);
	auto Maintask = Main(speakctrl, (char *)"Testmaintask");

	rtos::run();
	return 0;
}

