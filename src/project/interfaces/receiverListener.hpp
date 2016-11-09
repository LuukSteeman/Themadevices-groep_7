///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman
#pragma once
#include "../applicationLogic/messageLogic.hpp"
class ReceiverListener
{
public:
    virtual void msgReceived(MessageLogic msg) = 0;  
};
