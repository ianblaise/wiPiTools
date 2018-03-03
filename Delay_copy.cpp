#include "Delay.h"
void pause(int dur)
{
	Delay d;
	while (!d.over(dur)) {}
}

void Delay::start(int dur)
{
	if (!_over) return;
	start_clock = clock();
	_duration = dur;
}

void Delay::fukkit()
{
	_over = true;
	_duration = 0;
}

bool Delay::over()
{
	if (clock() >= start_clock + _duration) {
		_over = true;
		return _over;
	}
	_over = false;
	return _over;
}

bool Delay::over(int delay)
{
	this->start(delay);
	return over();
}

int Delay::time_left() const
{
	return start_clock + _duration - clock();
}

Delay::Delay()
{
	start_clock = std::clock();
	_over = true;
}

Delay::Delay(int dur)
{
	Delay();
	this->start(dur);
}

Delay::~Delay()
{
}
