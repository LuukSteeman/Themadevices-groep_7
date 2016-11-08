#include "shootCtrl.hpp"

shootCtrl::shootCtrl(transmitterctrl & trans) : trans(trans) {}

shootCtrl::run()
{
	while(1)
	{
		button = channel.read();
		if (button)
		{
			switch (button)
			{
				case '*':
					
			}
		}
	}
}