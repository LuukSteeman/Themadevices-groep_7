#include "speakercontroller.hpp"

void Speakercontroller::main()
{
	while (1) {
		int noteLength = hits.read();
		if (noteLength > 0)
		{
			play(noteLength);
		}
	}
}

void Speakercontroller::add(int hit)
{
	hits.write(hit);
}

void Speakercontroller::set_frequency(int freq)
{
	time = 1'000'000 / (2 * freq);
}

void Speakercontroller::play(int noteLength)
{
	for(int i = 0; i < noteLength; i++)
	{
		sleep(time * rtos::us);
		speak.set(1);
		sleep(time * rtos::us);
		speak.set(0);
	}
}