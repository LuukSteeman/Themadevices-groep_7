#pragma once
#include "../applicationLogic/messageLogic.hpp"
class ReceiverListener
{
    public:
    virtual void msgReceived(MessageLogic msg) = 0;  
};