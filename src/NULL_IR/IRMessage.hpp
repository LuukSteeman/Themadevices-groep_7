class IRMessage{
    private:
        int _id; //0 = spelleider 1-31 = speler
        int _data;
        unsigned int _error;
        bool checkChecksum(short data);
    public:
        IRMessage(int id, int data);
        IRMessage(short input);
        short encode();
        bool decode(short input);
        bool getError();

        void setId(int id);
        int getId();

        void setData(int data);
        int getData();
		
		const unsigned int STARTBITERROR = 1;
		const unsigned int OUTOFRANGE = 2;
		const unsigned int CHECKSUMERROR = 4;
};