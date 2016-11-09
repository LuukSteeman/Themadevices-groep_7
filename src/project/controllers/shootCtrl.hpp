#ifndef SHOOTTASK_HPP
#define SHOOTTASK_HPP

#include <rtos.hpp>
#include "transmitterctrl.hpp"
#include "keypadListener.hpp"
#include "Player.hpp"
#include "messageLogic.hpp"


///shootCtrl
//
///shootCtrl is an implementation of both rtos::task<> and KeyPadlistener.
///use the shootCtrl to communicate with a transmitterctrl through a keypad.
class shootCtrl : public rtos::task<256>, public KeypadListener
{
private:
	///The keychannel is a channel where button presses are stored.
	rtos::channel<char, 100> keychannel;

	///shootCtrl knows a transc as it calls the function transmitterctrl::run()
	Transmitterctrl & transc;

	///shootCtrl knows a Player entity object as the weaponID value is required to regulate the speed at which a player can shoot.
	Player & player;

	///msg is sent to the transmitterctrl so it knows exactly what message to send.
	MessageLogic msg;

	///main first gets the weaponID and then uses this to calculate the shootDelay.
	///It then continues to read the channel for the '*' character.
	///If it sees a '*' it will tell the transmitterctrl to send the msg and sleeps for shootDelay in milliseconds.
	void main();

	///The weaponId of the player.
	int weaponId;

	///THe shotdelay calculated based on the weaponID.
	int shotdelay;

	bool shoot = false;
public:

	///@param name is the name of the task for debugging purposes.
	///@param transc is the transmittercontroller used to send the messages when told to.
	///@param player is the player that uses the arduino, only the weaponID is required.
	shootCtrl(char * name, Transmitterctrl & transc, Player & player);

	///Keypressed is the interface function for communicating with this task through the keypad
	///@param key is the button that's pressed.
	void keyPressed(char key)
	{
		// keychannel.write(key);
		if( key == '*'){
			shoot = true;
		}
	}
};

#endif //SHOOTTASK_HPP