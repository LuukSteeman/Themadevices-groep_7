#ifndef GAMEMASTERCTRL_HPP
#define GAMEMASTERCTRL_HPP

#include <rtos.hpp>
#include "hwlib.hpp"
#include "messageLogic.hpp"
#include "transmitterctrl.hpp"
#include "keypadListener.hpp"


///GamemasterCtrl
//
///The GamemasterCtrl is used for a seperate application of the laser game library.
///The gamemasters job is limited to sending commands when the 'C' button is pressed.
///Following up a C press with numbers 1-9 adds that many minutes to the clock.
///Pressing 0 will send the signal to start the game.
class GamemasterCtrl : public rtos::task<>, public KeypadListener
{
private:

	///Channel on which the keypresses are received.
	rtos::channel<char, 10> commandChannel;

	///The message send when calling transmitterctrl.run();
	MessageLogic msg;

	///The transmitterctrl used to send commands to players.
	Transmitterctrl & transmitterctrl;

	///A temporary variable to store the button press.
	char buttonpressed;

public:

	///The constructor requires transmitterctrl reference and a name.
	///@param transmitterctrl is the transmitterctrl used to send the commands.
	///@param name is the name given to the task for debugging purposes only.
	GamemasterCtrl(Transmitterctrl & transmitterctrl, char * name);

	///keyPressed is an implementation of the keyPressed function of keypadListener.
	///@parameter button is the button press that will be written to the channel.
	void keyPressed(char button);

	///The main starts by waiting for a 'C' press
	///Once pressed it will wait for a numerical button press and send the msg based on which button was pressed.
	///When the 0 button is pressed, it will break from the while loop and suspend itself.
	///The gamemasters job is done by then and you could even turn it off completely.
	
	void main();
};

#endif //GAMEMASTERCTRL_HPP
