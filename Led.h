#pragma once
#include "Output.h"
#include "Delay.h"
class Led :
	public Output
{
public:
	void blink(Delay &delay); //will blink between delays.
	Led(int pin);
	~Led();
};

