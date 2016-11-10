#include "hwlib.hpp"
#include "messageLogic.hpp"
#include "bitTools.hpp"

MessageLogic::MessageLogic(int id, int data)
{
    if (id >= 0 && id <= 31)
    {
        _id = id;
    }
    else
    {
        _id = -1;
        _error |= OUTOFRANGE;
    }

    if (data >= 0 && data <= 31)
    {
        _data = data;
    }
    else
    {
        _data = -1;
        _error |= OUTOFRANGE;
    }
};

MessageLogic::MessageLogic(short input)
{
    decode(input);
};

MessageLogic::MessageLogic()
{
    _id = 0;
    _data = 0;
}

short MessageLogic::encode()
{

    //Initial value of data
    //short = 16 bits
    short returnData = 0;

    //Set Bit 0 to :
    returnData = returnData | (1 << 15);

    //Convert id to short and place it on position 1-5
    short id = _id << 10;
    returnData = returnData | id;

    //Convert data to short and place it on position 5-10
    short data = _data << 5;
    returnData = returnData | data;
    //Create checksum
    for (int i = 1; i <= 5; i++)
    {
        short checksum = getBit(i, returnData) ^ getBit(i + 5, returnData);
        checksum = checksum << (5 - i);
        returnData = returnData | checksum;
    }
    return returnData;
};

bool MessageLogic::checkChecksum(short data)
{
    for (int i = 1; i <= 5; i++)
    {
        if (!(getBit(10 + i, data) == (getBit(i, data) ^ getBit(i + 5, data))))
        {
            return false;
        }
    }
    return true;
};

bool MessageLogic::decode(short msg)
{
    _error = 0;
    _id = 0;
    _data = 0;
    if (!checkChecksum(msg))
    {
        _error |= CHECKSUMERROR;
    }
    if (!getBit(0, msg))
    {
        _error |= STARTBITERROR;
    }
    if (_error)
    {
        return false;
    }

    for (int i = 1; i <= 5; i++)
    {
        _id = _id | getBit(i, msg);
        if (i < 5)
        {
            _id = _id << 1;
        }
    }

    for (int i = 6; i <= 10; i++)
    {
        _data = _data | getBit(i, msg);
        if (i < 10)
        {
            _data = _data << 1;
        }
    }
    return true;
};

void MessageLogic::setId(int id)
{
    if (id >= 0 && id <= 31)
    {
        _id = id;
    }
    else
    {
        _id = -1;
        _error |= OUTOFRANGE;
    }
}

int MessageLogic::getId()
{
    return _id;
}

void MessageLogic::setData(int data)
{
    if (data >= 0 && data <= 31)
    {
        _data = data;
    }
    else
    {
        _data = -1;
        _error |= OUTOFRANGE;
    }
}

int MessageLogic::getData()
{
    return _data;
}

int MessageLogic::getError()
{
    return _error;
}