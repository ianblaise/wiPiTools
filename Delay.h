#pragma once
#include <ctime> //clock()
/*
*	Simple class to make managing
*   delays easier. This delay class
*	will not lock your code. 
*/
void pause(int dur); //pauses the program for "dur" seconds.
class Delay
{
public:
	void start(int dur); //starts the delay for "dur" seconds
	void fukkit(); //stops the delay immediately
	bool over(); //true when the delay is over
	bool over(int delay); //true when delay is over, but starts delay as well.
	int time_left() const; //get time left on current delay.
	Delay(); //Standard ctor
	Delay(int dur); //Standard ctor, but starts delay on creation.
	~Delay(); //destroy me.
private:
	bool _over; //over..
	int _duration; //duration..
	clock_t start_clock; //start clock..
};

