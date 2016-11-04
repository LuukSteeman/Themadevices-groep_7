#include "receiver.hpp"

void Receiver::addReceiverListener(ReceiverListener* listener){
     {
        if (listenerCount < maxListeners)
        {
            listeners[listenerCount] = listener;
            listenerCount++;
        }
    }
}

void Receiver::update(short msg){
    {
        for (int i = 0; i < listenerCount; i++)
        {
            listeners[i]->msgReceived(msg);
        }
    }
}