#include <hwlib.hpp>
#include <rtos.hpp>

#include "drawables/text.hpp"
#include "controllers/oled_controller.hpp"


class Main : rtos::task<> {


private:
	oled_controller oled_control;
	text t(const * oled_control, 2, "Hi");
	void main() {
		while (1) {
			t.draw();
			sleep(2 * rtos::s);
		};
	};

public:
	Main(const oled_controller * oled_control, char *name) : 
		oled_control(oled_control), task(name)
	{};
};


int main()
{
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(500);

	oled_buffered_d18_d21 oled_class;
    auto hw = oled_buffered_d18_d21();
    auto & oled = hw.oled;


    auto window1 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 0 ),
        hwlib::location( 96, 32));
    auto window2 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 32 ),
        hwlib::location( 96, 32));
    auto window3 = hwlib::window_part( 
        oled, 
        hwlib::location( 0, 64 ),
        hwlib::location( 32, 64));
     

    auto font_small = hwlib::font_default_8x8();
    auto font_big = hwlib::font_default_16x16();


    auto outstream1 = hwlib::window_ostream( window1, font_big );
    auto outstream2 = hwlib::window_ostream( window2, font_small );
    auto outstream3 = hwlib::window_ostream( window3, font_small );

	auto oled_control = oled_controller("OLED Controller", outstream1, outstream2, outstream3);
	auto Maintask = Main(oled_control, "Testmaintask");

	rtos::run();

	return 0;
}