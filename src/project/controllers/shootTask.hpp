#ifndef SHOOTTASK_HPP
#define SHOOTTASK_HPP

#include <rtos.hpp>
#include "controllers/transmitterctrl.hpp"
#include "interface/keypadListener.hpp"
#include "entity/player.hpp"
#include "applicationLogic/gunLogic.hpp"

class shootTask : public rtos::task<>, public keypadListener
{
public:
	Transmitterctrl & transc;
	shootTask(Transmitterctrl & transc, player.weapon weapon);
	player.weapon weapon;
	void add(weapon);
	void main();
private:
	rtos::channel<char, 10> shootChan;
};

#endif //SHOOTTASK_HPP