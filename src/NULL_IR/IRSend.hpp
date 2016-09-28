#include "rtos.hpp"
#include "hwlib.hpp"

class IRSend : public rtos::task<>{
    private:
        due::d2_36kHz ir;
        void sendBit(bool bit);
        void send(int speler,int data);
        void main();
    public:
        IRSend();
};