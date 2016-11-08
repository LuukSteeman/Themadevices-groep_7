#include "receiver.hpp"

void Receiver::addReceiverListener(ReceiverListener *listener)
{
    {
        if (listenerCount < maxListeners)
        {
            listeners[listenerCount] = listener;
            listenerCount++;
        }
    }
}

void Receiver::update(MessageLogic msg)
{
    {
        // if (msg == lastReceived && lastReceivedTime < (hwlib::target::now_ticks() + (84 * 5000)))
        // {
        //     hwlib::cout << "Double Message";
        //     return;
        // }
        // lastReceived.setId(msg.getId());
        // lastReceived.setData(msg.getData());
        // lastReceivedTime = hwlib::target::now_ticks();
        for (int i = 0; i < listenerCount; i++)
        {
            listeners[i]->msgReceived(msg);
        }
    }
}