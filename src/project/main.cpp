#include <hwlib.hpp>
#include <rtos.hpp>

#include "drawables/text.hpp"
#include "controllers/oled_controller.hpp"
#include "boundary/oled.hpp"


class Main : rtos::task<> {


private:
	oled_buffered_d18_d21	 oled;
	oled_controller oled_control((char*)"OLED Controller Task");
	text t(&oled_control, 2, "Hi");
	void main() {
		while (1) {
			t.draw();
			sleep(2 * rtos::s);
		};
	};

public:
	Main(oled_controller & oled_control, char *name) : 
		oled_control(oled_control), task(name)
	{};
};


int main()
{
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);

	auto oled_control = oled_controller((char*)"Controller");
	auto Maintask = Main(&oled_control, "Testmaintask");

	rtos::run();

	return 0;
}