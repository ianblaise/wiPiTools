#pragma once
class Output
{
public:
	void on();
	void off();
	int get_pin() const;
	bool is_on() const;
	Output(int pin);
	~Output();
private:
	int _pin;
	bool _on;
};

