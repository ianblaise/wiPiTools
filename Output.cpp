#include "Output.h"



void Output::on()
{
	//pinMode(pin, HIGH);
	_on = true;
}

void Output::off()
{
	//pinMode(pin, LOW);
	_on = false;
}

int Output::get_pin() const
{
	return _pin;
}

bool Output::is_on() const
{
	return _on;
}

Output::Output(int pin)
{
	_pin = pin;
	off();
}


Output::~Output()
{
	off();
}
