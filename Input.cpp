#include "Input.h"
#include "Delay.h"

std::string Input::to_string() const 
{
	std::ostringstream ss;
	if(_name.size() > 0) {
		ss << _name << " , Pin: " << _pin;
		return ss.str();
	}
	ss << "Pin " << _pin;
	return ss.str();
}

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

Input::Input(int pin, bool analog) : Input(pin)
{
	_analog = analog;
}

Input::Input(int pin, std::string name) : Input(pin) 
{
	_name = name;
}

Input::Input(int pin, std::string name, bool analog)
{
	_pin = pin;
	_name = name;
	_analog = analog;
}

Input::~Input()
{
}
