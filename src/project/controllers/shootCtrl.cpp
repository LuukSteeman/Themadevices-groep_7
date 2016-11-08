#include "shootCtrl.hpp"

shootCtrl::shootCtrl(char * name, Transmitterctrl & transc, Player & player) :
task(name),
keychannel(this, "channel for keypresses"),
transc(transc),
player(player)
{}

void shootCtrl::main()
{

	msg = MessageLogic(10, player.getWeapon());
	while(1)
	{
		if (keychannel.read() == '*')
		{
			transc.run(msg, this);
			sleep(100 * rtos::ms);
		}

		sleep(1 * rtos::ms);
	}
}
