#include "Output.h"

std::string Output::to_string() const {
	std::ostringstream ss;
	if(_name.size() > 0) {
		ss << _name << " , Pin: " << _pin;
		return ss.str();
	}
	ss << "Pin " << _pin;
	return ss.str();
}

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

Output::Output(int pin, std::string name) : Output(pin)
{
	_name = name;
}


Output::~Output()
{
	off();
}
