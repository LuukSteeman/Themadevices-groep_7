#include "setupController.hpp"

setupController::setupController():task(), message_channel(this, "Setup MessageLogic Channel"), key_channel(this, "Setup Key Channel"){
	thePlayer = Player();
}

void setupController::keyPressed(char x){
	key_channel.write(x);
}

void setupController::read_key_channel(){
	pressed_key = key_channel.read();
}

char setupController::get_key(){
	return pressed_key;
}

void setupController::msgReceived(MessageLogic msg){
	message_channel.write(msg);
}

void setupController::read_message_channel(){
	received_message = message_channel.read();
}

void setupController::determineWeapon(Player &thePlayer){
	if (pressed_key > 0 && pressed_key < 10){
		thePlayer.setWeapon(pressed_key);
	}
}

void setupController::determineTime(int timeValue){}	// To be added

void setupController::determinePlayerID(Player &thePlayer){
	//int ID = PlayerID::getID();
	//thePlayer.setPlayerID(ID);		// Function needs to be added still
}