#pragma once

class IRMessage{
    private:
        int _id; //0 = spelleider 1-31 = speler
        int _data;
        unsigned int _error = 0;
        bool checkChecksum(short data);
    public:
        IRMessage(int id, int data);
        IRMessage(short input);
        IRMessage();
        short encode();
        bool decode(short input);
        int getError();

        void setId(int id);
        int getId();

        void setData(int data);
        int getData();
		
		static const unsigned int STARTBITERROR = 1;
		static const unsigned int OUTOFRANGE = 2;
		static const unsigned int CHECKSUMERROR = 4;
};