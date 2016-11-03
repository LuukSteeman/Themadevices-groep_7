#pragma once

class ReceiverListener
{
    public:
    virtual void msgReceived(short msg) = 0;  
};