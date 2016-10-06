/// @file
/// NULL_IR_RECEIVER 

#include "IRReceiver.hpp"

void IRReceiver::detect()
{

	msg = 0;
	last_bit = 0;

	auto test = hwlib::target::pin_out(hwlib::target::pins::d10);
	auto ir_pin = hwlib::target::pin_in(hwlib::target::pins::d3);
	auto out_pin = hwlib::target::pin_out(hwlib::target::pins::d4);
	

	while (ir_pin.get() == false){
	test.set(1);
	sleep( 200 * rtos::us);
	test.set(0);
	 }


	sleep( 1200 * rtos::us);

	last_bit = !ir_pin.get();
	out_pin.set( last_bit);
	sleep( 10 * rtos::us);

	out_pin.set(0);

	if (last_bit == 1)
	{
		while(ir_pin.get() == false)
		{
			sleep(10 * rtos::us);
		}
	}
	

}

void IRReceiver::main()
{
	for(;;)
	{
		detect();
	}
}