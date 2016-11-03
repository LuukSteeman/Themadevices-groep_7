#include <hwlib.hpp>
#include <rtos.hpp>

#include "boundary/receiver.hpp"
#include "controllers/receiverHandler.hpp"
#include "interfaces/receiverListener.hpp"

class x : public ReceiverListener
{
  public:
    void msgReceived(short msg)
    {
        hwlib::cout << msg;
    }
};

int main()
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    Receiver r(hwlib::target::pins::d12);
    ReceiverHandler rh(r);

    x X;
    r.addReceiverListener(&X);

    rtos::run();
}