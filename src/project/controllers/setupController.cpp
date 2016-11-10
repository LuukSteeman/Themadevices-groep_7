#include "setupController.hpp"

SetupController::SetupController(Player &thePlayer, PlayerID & id, TransferController & transferctrl, rtos::flag& gameStartedFlag):
task("Setuptask"),
message_channel(this, "Setup MessageLogic Channel"),
key_channel(this, "Setup Key Channel"),
gameStartedFlag(gameStartedFlag),
gameTimer(this, "Game Length Timer"),
gameEndedPool("Game Ended Pool"),
thePlayer(thePlayer),
id(id),
transferctrl(transferctrl)
{
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

void SetupController::addGameTime(int timeAdded){
    timeSet += timeAdded;
}

void SetupController::startTimer(){
    timeSet *= 60000;
    gameTimer.set(timeSet);
}

void SetupController::determinePlayerID(){
	int receivedID = id.getID();
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
		hwlib::cout << thePlayer.getWeapon();
        hwlib::cout << "Goed zo!\n Je hebt je wapen gekozen!!!!11!!1!!22$#";
	}
    while(1){
        read_message_channel();
        if (gotMessage){
    		int received_data = received_message.getData();
    		if (received_data == 0){
                hwlib::cout << "game startd";
                gameEndedPool.write(0);
    			setGameFlag();
                startTimer();
                break;
    		}
    		else{
    			addGameTime(received_data);
                hwlib::cout << received_data << "added \n";
    		}
    		gotMessage = 0;
    	}
    }
    // gameEndedPool.write(1);
    // hwlib::cout << "Game finished";
    // read_key_channel();
    // if (pressed_key){
    //     transferctrl.run(this);
    //     hwlib::cout << "Transferred";
    // }
    // suspend();
}