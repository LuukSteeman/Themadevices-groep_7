class IRMessage{
    private:
        int _id; //0 = spelleider 1-31 = speler
        int _data;
    public:
        IRMessage(int id, int data);
        IRMessage(short input);
        short encode();
        bool decode(short input);
        bool errors();
}