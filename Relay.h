#pragma once
#include <vector>
#include <iostream>
#include "Delay.h"
class Relay
{
public:
	void reset(); //turns turns all relays off
	void on(); //turns on a single relay
	void on(int relay); //turns on a single specified relay
	void off(); //turns off a single relay
	void off(int relay); //turns off a single specified relay
	void display_status(); //prints the status of relay(s)
	int get_status() const; //returns a relay's status
	int get_status(int relay) const; //returns a specified relay's status
	int get_pin() const; //returns the wiringPi pin 
	bool is_normally_open() const; //returns true if normally open
	bool is_manager() const;
	int status; //holds status of relay
	size_t size();
	Relay(int pin, bool normally_open); //on the fly, one relay
	Relay(std::vector<Relay> relays); //takes a bunch of relays
	Relay get_relay(int num) const; //pulls out a relay
	~Relay();
private:
	int pin; //for the one relay
	bool normally_open; //if normally open
	std::vector<Relay> relays; //our relays
	bool manager;
};

