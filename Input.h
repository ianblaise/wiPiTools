#pragma once
#include "Delay.h"
class Input
{
public:
	int read();
	int get_pin() const;
	bool is_analog() const;
	Input(int pin);
	Input(int pin, bool analog);
	~Input();
private:
	int _pin;
	bool _analog;
	Delay _delay;
};

