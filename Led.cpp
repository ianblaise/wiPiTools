#include "Led.h"
#include <iostream>


void Led::blink(Delay &delay)
{
	if (delay.over()) {
		std::cout << "SWITCHING STATES" << std::endl;
		if (is_on()) {
			off();
			return;
		}
		on();
	}
}

Led::Led(int pin) : Output(pin)
{
}


Led::~Led()
{
}
