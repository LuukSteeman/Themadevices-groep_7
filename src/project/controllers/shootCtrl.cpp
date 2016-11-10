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
	shotdelay = GunLogic::calcShootDelay(weaponId);
	msg = MessageLogic(10, weaponId);
	while(1)
	{
		// wait(keychannel);
		// char x = keychannel.read();
		// if ( x == '*')
		// {
			if(shoot){
				transc.run(msg, this);
				shoot=false;
			}else{
				sleep(1*rtos::ms);
			}
			// sleep(shotdelay * rtos::ms);
		// }
		sleep(10 * rtos::ms);
	}
}
