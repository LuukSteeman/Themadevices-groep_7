#include "setupController.hpp"

SetupController::SetupController(Player &thePlayer):
task("Setuptask"),
message_channel(this, "Setup MessageLogic Channel"),
key_channel(this, "Setup Key Channel"),
gameStartedFlag(this, "Start up flag"),
gameTimer(this, "Game Length Timer"),
gameEndedPool("Game Ended Pool"),
thePlayer(thePlayer)
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
    hwlib::cout << timeSet;
}

void SetupController::determinePlayerID(){
	int receivedID = PlayerID::getID();
	thePlayer.setPlayerID(receivedID);
}

void SetupController::setGameFlag(){
    gameStartedFlag.set();
}

void SetupController::main(){
	determinePlayerID();
	hwlib::cout << "Select weapon\n";
	read_key_channel();
	if (pressed_key){
		thePlayer.setWeapon( pressed_key - '0' );
		pressed_key = 0;
		hwlib::cout << "You've selected: " << thePlayer.getWeapon() << "\n";
	}
    while(1){
		hwlib::cout << "waiting for message from gamemaster\n";
        read_message_channel();
        if (gotMessage){
    		int received_data = received_message.getData();
    		if (received_data == 0){
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
    hwlib::cout << "\n=====================\ngame started\n";
	// hwlib::cout << sleep_timer << "\n";
	hwlib::cout << "Time: " << hwlib::now_us() << "\n";
	hwlib::cout << *this << "\n";
    sleep(4294967295);
    hwlib::cout << "Game finished\n";
	// hwlib::cout << sleep_timer << "\n";
	hwlib::cout << *this << "\n";
	hwlib::cout << "Time: " << hwlib::now_us() << "\n";
	gameEndedPool.write(1);
    // read_key_channel();
    // if (pressed_key){
	//     TransferController transferctrl(ds);
    //     transferctrl.run(this);
    //     hwlib::cout << "Transferred";
    // }
    suspend();
}