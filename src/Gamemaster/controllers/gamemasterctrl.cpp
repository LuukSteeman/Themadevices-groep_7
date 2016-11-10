#include "gamemasterctrl.hpp"

GamemasterCtrl::GamemasterCtrl(Transmitterctrl & transmitterctrl, char * name):
task(name),
commandChannel(this, "Channel for receiving commands to send"),
transmitterctrl(transmitterctrl)
{}

void GamemasterCtrl::keyPressed(char button)
{
	commandChannel.write(button);
}

void GamemasterCtrl::main()
{
	while(1)
	{
		sleep( 50 * rtos::ms);
		char buttonpressed = commandChannel.read();
		if (buttonpressed == 'C')
		{
			hwlib::cout << "waiting for command\n";
			sleep(50 * rtos::ms);
			buttonpressed = commandChannel.read();
			if(buttonpressed >= '0' && buttonpressed <= '9')
				hwlib::cout << buttonpressed;
				msg = MessageLogic(0, (buttonpressed - '0'));
				transmitterctrl.run(msg, this);
				if(buttonpressed == '0')
				{
					break;
			}
		}
	}
	hwlib::cout << "starting game";
	suspend();
}