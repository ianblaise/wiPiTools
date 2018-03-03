#pragma once
#include "Delay.h"
#include <string>
#include <sstream>
class Input
{
public:
	std::string to_string() const;
	int read();
	int get_pin() const;
	bool is_analog() const;
	Input(int pin);
	Input(int pin, bool analog);
	Input(int pin, std::string name);
	Input(int pin, std::string name, bool analog);
	~Input();
private:
	int _pin;
	bool _analog;
	Delay _delay;
	std::string _name;
};

