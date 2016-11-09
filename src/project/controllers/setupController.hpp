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
#include "../controllers/transferController.hpp"

class SetupController : public rtos::task<>, public KeypadListener, public ReceiverListener{
private:
	rtos::channel< MessageLogic, 1024 > message_channel;
	rtos::channel< char, 1024 > key_channel;
    rtos::flag gameStartedFlag;
    rtos::timer gameTimer;
    rtos::pool< bool > gameEndedPool;
	char pressed_key;
	MessageLogic received_message;
    bool gotMessage;
	Player &thePlayer;
	PlayerID & id;
    TransferController & transferctrl;
    int timeSet;
public:
    SetupController(Player &thePlayer, PlayerID & id, TransferController & transferctrl);

	void keyPressed(char x);

	void read_key_channel();

	char get_key();

	void msgReceived(MessageLogic msg);

	void read_message_channel();

	void determineWeapon();

	void startTimer();

	void determinePlayerID();

    void setGameFlag();

	void main();
};

#endif //SETUPCONTROLLER_HPP