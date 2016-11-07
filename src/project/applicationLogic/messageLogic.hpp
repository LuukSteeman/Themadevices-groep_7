#pragma once

/**
    Message logic object. Used Troughout the system to comunicate messages
*/
class MessageLogic
{
  private:
    int _id; //0 = spelleider 1-31 = speler
    int _data;
    unsigned int _error = 0;
    bool checkChecksum(short data);

  public:
    /**
        Create a message object
        @param Player ID
        @param data to be send.
    */
    MessageLogic(int id, int data);
    /**
        Create a message object
        @param message in bits, will decode it.
    */
    MessageLogic(short input);
    /**
        Create a empty message object
    */
    MessageLogic();
    /**
        Encode the MessageLogic object to its short representation
        @return short representation(including checksum) of MessageLogic
    */
    short encode();
    /**
        Decode a short to store in internal representation
        @param short representation(with checksum) of message object
        @return returns true if a error occured
    */
    bool decode(short input);

    /**
        Return error value.
        You can check for a specific error by or-ing with 

        @return error value
    */
    int getError();

    /**
        Set the internal id of MessageLogic Object
        @param id 
    */
    void setId(int id);
    /**
        Get the internal id
        @return internal id
    */
    int getId();

    /**
        Set the internal data of MessageLogic Object
        @param data
    */
    void setData(int data);
    /**
        Get internal data
        @return internal data
    */
    int getData();

    /**
        Value to be used for checking for start bit error (no startbit found)
    */
    static const unsigned int STARTBITERROR = 1;
    /**
        Value to be used for checking for out of range
    */
    static const unsigned int OUTOFRANGE = 2;
    /**
        Value to be used for checking for checksum error
    */
    static const unsigned int CHECKSUMERROR = 4;
};