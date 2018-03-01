#include "Relay.h"

void Relay::reset()
{
	Delay d;
	if (pin != -1) {
		off();
		return;
	}
	for (size_t i = 0; i < relays.size(); i++) {
		relays.at(i).off();
		pause(25);
	}
}

void Relay::on()
{
	if (relays.size() > 0) return;
	if (normally_open) {
		//digitalWrite(pin, HIGH);
		status = 1;
		return;
	}
	//digitalWrite(pin, LOW);
	status = 1;
}

void Relay::on(int relay)
{
	if (relay < 0 || relay >= (int)relays.size()) {
		return;
	}

	Relay *r = &relays.at(relay);
	if (r->is_normally_open()) {
		//digitalWrite(r.get_pin(), HIGH);
		r->status = 1;
		return;
	}
	//digitalWrite(r.get_pin(), LOW);
	r->status = 1;
}

void Relay::off()
{
	if (relays.size() > 0) return;
	if (normally_open) {
		//digitalWrite(pin, LOW);
		status = 0;
		return;
	}
	//digitalWrite(pin, HIGH);
	status = 0;
}

void Relay::off(int relay)
{
	if (relay < 0 || relay >= (int)relays.size()) {
		return;
	}

	Relay *r = &relays.at(relay);
	if (r->is_normally_open()) {
		//digitalWrite(r.get_pin(), LOW);
		r->status = 0;
		return;
	}
	//digitalWrite(r.get_pin(), HIGH);
	r->status = 0;
}

void Relay::display_status()
{
	if (pin != -1)
	{
		std::cout << "RELAY #1: " << pin << ", " << status << std::endl;
		return;
	}
	for (size_t i = 0; i < relays.size(); i++) {
		std::cout << "RELAY #" << i << " " << relays.at(i).get_pin() << ", " 
			<< relays.at(i).get_status() << std::endl;
	}
}

int Relay::get_status() const
{
	return status;
}

int Relay::get_status(int relay) const
{
	if (relay < 0 || relay > (int)relays.size()) return 0;
	return relays.at(relay).get_status();
}

int Relay::get_pin() const
{
	return pin;
}

bool Relay::is_normally_open() const
{
	return normally_open;
}

bool Relay::is_manager() const
{
	return manager;
}

size_t Relay::size()
{
	if (relays.size() == 0 && pin != -1) return 1;
	return relays.size();
}

Relay::Relay(int pin, bool normally_open)
{
	this->manager = false;
	this->pin = pin;
	this->normally_open = normally_open;
	//pinMode(pin, INPUT);
	this->off();
	status = 0;
}

Relay::Relay(std::vector<Relay> relays)
{
	this->manager = true;
	this->pin = -1;
	this->relays = relays;
	for (size_t i = 0; i < relays.size(); i++) {
		//pinMode(r.get_pin(), INPUT);
		Relay *r = &relays.at(i);
		r->off();
		r->status = 1;
		
	}
}

Relay Relay::get_relay(int relay) const
{
	if (relay > (int)relays.size() || relay < 0) {
		return relays.at(0);
	}
	return relays.at(relay);
}

Relay::~Relay()
{
}
