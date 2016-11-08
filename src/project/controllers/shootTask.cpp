#include "controllers/shootTask.hpp"

shootTask::shootTask(Transmitterctrl & transc, player.weapon weapon) :
transc(transc),
weapon(weapon),
shootChan(this, "Channel with shoot messages")
{}

void shootTask::main()
{
	while (1)
	{
		char msg = shootChan.read();
		while (msg == '*')
		{
			transc.add(weapon.dmg);
			sleep( weapon.cooldown * rtos::ms);
			msg = shootChan.read();
		}
		sleep( 1 * rtos::ms);
	}
}

void shootTask::add(weapon)
{
	shootChan.write(weapon);
}