#include "shootCtrl.hpp"
#include "gunLogic.hpp"

shootCtrl::shootCtrl(char * name, Transmitterctrl & transc, Player & player) :
task(name),
keychannel(this, "channel for keypresses"),
transc(transc),
player(player)
{}

void shootCtrl::main()
{

	weaponId = player.getWeapon();
	shotdelay = calcShootDelay(weaponId);
	msg = MessageLogic(10, weaponId);
	while(1)
	{
		if (keychannel.read() == '*')
		{
			transc.run(msg, this);
			sleep(shotdelay * rtos::ms);
		}

		sleep(1 * rtos::ms);
	}
}
