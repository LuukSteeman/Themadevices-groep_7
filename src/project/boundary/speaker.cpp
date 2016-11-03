#include "speaker.hpp"

Speaker::Speaker(hwlib::pin_out & lsp) : lsp(lsp)
{}

void Speaker::set_frequency(int freq)
{
	frequency = freq;
}

void Speaker::play()
{

	lsp.set(1);
	hwlib::wait_ms(1000/frequency);
	lsp.set(0);
	hwlib::wait_ms(1000/frequency);
}
