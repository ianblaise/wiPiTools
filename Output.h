#pragma once
#include <string>
#include <sstream>
class Output
{
public:
	void on();
	void off();
	int get_pin() const;
	bool is_on() const;
	std::string to_string() const;
	Output(int pin);
	Output(int pin, std::string name);
	~Output();
private:
	int _pin;
	bool _on;
	std::string _name;
};

