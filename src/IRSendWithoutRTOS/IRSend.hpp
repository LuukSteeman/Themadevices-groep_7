#include "hwlib.hpp"
#include "IRMessage.hpp"
class IRSend{
    private:
        due::d2_36kHz ir;
        void sendBit(bool bit);
        void main();
    public:
        IRSend();
        void send(IRMessage m);
};