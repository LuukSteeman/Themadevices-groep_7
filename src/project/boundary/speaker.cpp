#include "speaker.hpp"

Speaker::Speaker(hwlib::pin_out & lsp) : lsp(lsp)
{}

void Speaker::set(int m)
{
	lsp.set(m);
}