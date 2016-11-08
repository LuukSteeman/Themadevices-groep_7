#ifndef SETUPCONTROLLER_HPP
#define SETUPCONTROLLER_HPP

#include "rtos.hpp"
//#include "../controllers/timer_controller.hpp"
#include "../controllers/receiverHandler.hpp"
#include "../interfaces/keypadListener.hpp"
#include "../interfaces/receiverListener.hpp"
#include "../entity/player.hpp"
#include "../boundary/playerID.hpp"
#include "../applicationLogic/messageLogic.hpp"

class setupController : public rtos::task<>, public KeypadListener, public ReceiverListener{
private:
	rtos::channel< char, 1024 > key_channel;
	rtos::channel< MessageLogic, 1024 > message_channel;
	char pressed_key;
	MessageLogic received_message;
	Player thePlayer;
public:
	setupController();

	void keyPressed(char x);

	void read_key_channel();

	char get_key();

	void msgReceived(MessageLogic msg);

	void read_message_channel();

	void determineWeapon(Player &thePlayer);

	void determineTime(int timeValue);	// To be added

	void determinePlayerID(Player &thePlayer);
};

#endif //SETUPCONTROLLER_HPP