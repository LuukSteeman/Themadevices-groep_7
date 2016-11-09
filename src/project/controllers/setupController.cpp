#include "setupController.hpp"

SetupController::SetupController(Player &thePlayer):task("Setuptask"), message_channel(this, "Setup MessageLogic Channel"), key_channel(this, "Setup Key Channel"), gameStartedFlag(this, "Game Started Flag"), thePlayer(thePlayer){
	gotMessage = 0;
}

void SetupController::keyPressed(char x){
	key_channel.write(x);
}

void SetupController::read_key_channel(){
	pressed_key = key_channel.read();
}

char SetupController::get_key(){
	return pressed_key;
}

void SetupController::msgReceived(MessageLogic msg){
	message_channel.write(msg);
}

void SetupController::read_message_channel(){
	received_message = message_channel.read();
	gotMessage = 1;
}

void SetupController::determineWeapon(){
	if (pressed_key > 0 && pressed_key < 10){
		thePlayer.setWeapon(pressed_key);
	}
}

void SetupController::determineTime(int timeValue){}	// To be added

void SetupController::determinePlayerID(){
	int receivedID = PlayerID::getID();
	thePlayer.setPlayerID(receivedID);
}

void SetupController::setGameFlag(){
    gameStartedFlag.set();
}

void SetupController::main(){
	determinePlayerID();
	read_key_channel();
	if (pressed_key){
		thePlayer.setWeapon( pressed_key - '0' );
		pressed_key = 0;
	}
	read_message_channel();
	if (gotMessage){
		int received_data = received_message.getData();
		if (received_data == 0){
			setGameFlag();
		}
		else{
			determineTime(received_data);
		}
		gotMessage = 0;
	}
	suspend();
}