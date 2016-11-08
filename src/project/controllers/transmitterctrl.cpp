#include "transmitterctrl.hpp"
#include "bitTools.hpp"

Transmitterctrl::Transmitterctrl( Transmitter & trans):
trans(trans)
{}

void Transmitterctrl::run(MessageLogic m, rtos::task_base * task)
{
    unsigned short data = m.encode();
    for (int ii = 0; ii < 2; ii++)
    {
        for (int i = 0; i < 16; i++)
        {
            trans.sendBit(getBit(i, data), task);
        }
        if (ii == 0)
        {
            task->sleep(3 * rtos::ms);
        }
    }
}