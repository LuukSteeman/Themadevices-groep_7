#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRReceiver.hpp"
#include "IRSend.hpp"
#include "IRMessage.hpp"

class Main: rtos::task<>{
    IRSend & send;
    private:
        void main(){
                 sleep(1 * rtos::s);
                 while(1){
                    send.add(IRMessage(0b11111, 0b11111));
                    sleep(1* rtos::s);
                 };
        };
    public:
        Main(IRSend & send,char * name):
        task(name),
        send(send)
        {};
};

int main()
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    // wait for the PC console to start
    hwlib::wait_ms(500);
    auto IRSenderTask = IRSend((char *)"Blinker");
    auto MainTask = Main(IRSenderTask,(char *)"main");
    auto IRReceiverTask = IRReceiver();
    rtos::run();
    return 0;
}