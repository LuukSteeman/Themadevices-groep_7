#include "IRMessage.hpp"

IRMessage::IRMessage(int id, int data){
    if(id>=0 && id<=31){
        _id = id;
    }else{
        _id = -1;
        _error |= OUTOFRANGE;
    }

    if(data>=0 && data<=31){
        _data = data;
    }else{
        _data = -1;
        _error |= OUTOFRANGE;
    }
};

IRMessage::IRMessage(short input){
    decode(input);
};

bool getBit(int position, short data){
    return (data >> (15-position))&1;
}

short IRMessage::encode(){

    //Initial value of data
    //short = 16 bits
    short returnData = 0;

    //Set Bit 0 to 1
    returnData = returnData | (1<<15);

    //Convert id to short and place it on position 1-5
    short id = _id << 10;
    returnData = returnData | id;

    //Convert data to short and place it on position 5-10
    short data = _data << 5;
    returnData = returnData | data;
    
    //Create checksum
    for(int i = 1; i<=5;i++){
        short checksum = getBit(i,returnData) ^ getBit(i+5,returnData);
        checksum = checksum << 5 - i;
        returnData = returnData | checksum;
    }
    return returnData;
};

bool IRMessage::checkChecksum(short data){
    for(int i = 1; i<=5;i++){
        if(!( getBit(10+i,data) == getBit(i,data) ^ getBit(i+5,data))){
            return false;
        }
    }
    return true;
};


bool IRMessage::decode(short msg){
    _error = 0;
    if(!checkChecksum(msg)){
        _error |= CHECKSUMERROR;
    }	
    if(!getBit(0,msg)){
        _error |= STARTBITERROR;
    }
    if(_error){
        return false;
    }
    
	for(int i = 1; i<=5; i++){
        _id = _id | getBit(i,msg);
        if(i<5){
            _id = _id << 1;
        }
    }
    
    for(int i = 6; i<=10; i++){
        _data = _data | getBit(i,msg);
        if(i<10){
            _data = _data << 1;
        }
    }
};

void IRMessage::setId(int id){
    if(id>=0 && id<=31){
        _id = id;
    }else{
        _id = -1;
        _error |= OUTOFRANGE;
    }
}

int IRMessage::getId(){
    return _id;
}

void IRMessage::setData(int data){
    if(data>=0 && data<=31){
        _data = data;
    }else{
        _data = -1;
        _error |= OUTOFRANGE;
    }
}

int IRMessage::getData(){
    return _data;
}

int IRMessage::getError(){
	return _error;
}