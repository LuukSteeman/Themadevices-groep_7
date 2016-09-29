#include "rtos.hpp"
#include "hwlib.hpp"
#include "IRMessage.hpp"
class IRSend : public rtos::task<>{
    private:
        rtos::channel< IRMessage, 10 > messages;
        due::d2_36kHz ir;
        void sendBit(bool bit);
        void main();
    public:
        IRSend(char * name);
        void add(IRMessage m);
};