#include "speakercontroller.hpp"

void Speakercontroller::main()
{
	while (1) {
		int noteLength = hits.read();
		if (noteLength > 0)
		{
			speak.set(1);

			sleep( noteLength * rtos::ms);

			speak.set(0);

			sleep( noteLength * rtos::ms);
		}
	}
}

void Speakercontroller::add(int hit)
{
	hits.write(hit);
}