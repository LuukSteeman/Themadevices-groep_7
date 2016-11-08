#ifndef SHOOTTASK_HPP
#define SHOOTTASK_HPP

#include <rtos.hpp>
#include "transmitterctrl.hpp"
#include "keypadListener.hpp"
#include "entity/player.hpp"
#include "applicationLogic/gunLogic.hpp"
#include "messageLogic.hpp"

class shootCtrl : public rtos::task<>, public KeypadListener
{
private:
	rtos::channel<char, 10> keychannel;
	Transmitterctrl & transc;
	Player & player;
	MessageLogic msg;
	void main();

public:
	shootCtrl(char * name, Transmitterctrl & transc, Player & player);
	void keyPressed(char key) override
	{
		keychannel.write(key);
	}
};

#endif //SHOOTTASK_HPP