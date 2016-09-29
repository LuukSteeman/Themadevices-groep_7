#include "IRMessage.hpp"

IRMessage::IRMessage(int id, int data){
    if(id>=0 && id<=31){
        _id = id;
    }else{
        _id = -1;
        error = true;
    }

    if(data>=0 && data<=31){
        _data = data;
    }else{
        _data = -1;
        error = true;
    }
};

IRMessage::IRMessage(short input){
    decode(input);
};

bool getBit(int position, short data){
    return (data >> (15-position))&1;
}

short IRMessage::encode(){
    short returnData = 0;
    returnData = returnData | (1<<15);
    short id = _id << 10;
    returnData = returnData | id;
    short data = _data << 5;
    returnData = returnData | data;
    
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

void IRMessage::decode(short data){
    if(!checkChecksum(data)){
        error = true;
        return;
    }
    if(!getBit(0,data)==1){
        error = true;
        return;
    }
};