#include "Delay.h"
void pause(int duration)
{
	Delay d;
	while (!d.over(duration)) {}
}

void Delay::start(int duration)
{
	if (!_over) return;
	_clock = clock();
	_duration = duration;
}

void Delay::cancel()
{
	_over = true;
	_duration = 0;
}

bool Delay::over()
{
	if (clock() >= _clock + _duration) {
		_over = true;
		return _over;
	}
	_over = false;
	return _over;
}

bool Delay::over(int duration)
{
	this->start(duration);
	return over();
}

int Delay::time_left() const
{
	return _clock + _duration - clock();
}

Delay::Delay()
{
	_clock = std::clock();
	_over = true;
}

Delay::Delay(int duration)
{
	Delay();
	this->start(duration);
}

Delay::~Delay()
{
}
