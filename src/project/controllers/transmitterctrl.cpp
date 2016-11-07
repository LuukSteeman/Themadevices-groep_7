#include "transmitterctrl.hpp"
#include "bitTools.hpp"

Transmitterctrl::Transmitterctrl(char * name, Transmitter & trans):
task(name),
trans(trans),
chan(this, "MessageLogic channel")
{}

void Transmitterctrl::add(IRMessage m)
{
	chan.write(m);
}

void Transmitterctrl::main()
{
	while(1)
	{
		auto m = chan.read();
        unsigned short data = m.encode();
        for (int ii = 0; ii < 2; ii++)
        {
            for (int i = 0; i < 16; i++)
            {
                trans.sendBit(getBit(i, data), this);
            }
            if (ii == 0)
            {
                sleep(3 * rtos::ms);
            }
        }
    }
}