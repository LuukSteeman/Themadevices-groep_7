#include "hwlib.hpp"
#include "rtos.hpp"
#include "IRReceiver.hpp"
#include "IRSend.hpp"
#include "IRMessage.hpp"

class Main : rtos::task<>
{
    IRSend &send;

  private:
    void main()
    {
        while (1)
        {
        sleep(10 * rtos::s);
            send.add(IRMessage(31, 31));
            sleep(5 * rtos::s);
        };
    };

  public:
    Main(IRSend &send, char *name) : task(name),
                                     send(send){};
};

int main()
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    // wait for the PC console to start
    hwlib::wait_ms(500);
    auto IRSenderTask = IRSend((char *)"IRSender");
    auto IRReceiverTask = IRReceiver((char *)"IRReceiver");
    auto MainTask = Main(IRSenderTask, (char *)"main");
    rtos::run();
    return 0;
}