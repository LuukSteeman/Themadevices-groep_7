#include "speaker.hpp"

Speaker::Speaker(hwlib::pin_out & lsp) : lsp(lsp)
{}

void Speaker::set(int m)
{
	if (m == 0)
	{
		lsp.set(0);
	}
	else
	{
		lsp.set(1);
	}
}