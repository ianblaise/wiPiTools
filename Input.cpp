#include "Input.h"
#include "Delay.h"
int Input::read()
{
	if (_delay.over()) {
		_delay.start(25);
		if (!_analog)
			//return digitalRead(_pin);
			return 0;
		//return analogRead(_pin);
	}
}

int Input::get_pin() const
{
	return _pin;
}

bool Input::is_analog() const
{
	return _analog;
}

Input::Input(int pin)
{
	_pin = pin;
}

Input::Input(int pin, bool analog)
{
	_pin = pin;
	_analog = analog;
}

Input::~Input()
{
}
