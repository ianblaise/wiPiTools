#include <iostream>
#include "Delay.h"
#include "Relay.h"
#include "Led.h"

#include <stdlib.h>
using namespace std;
//Nested delays should be longer.
int main() {
	Led led(1);
	Delay d(5000);
	Delay f(1000);
	Delay ledDelay(500);

	while (true) {
		f.start(10);
		ledDelay.start(500);
		if (f.over()) {
			led.blink(ledDelay);
			cout << led.is_on() << endl;
		}
	}

	Delay main;
	Relay fanRelay(18, true);
	Relay motorRelay(33, true);
	Relay ledRelay(32, false);

	vector<Relay> relays{ fanRelay, motorRelay, ledRelay };

	Relay relayManager(relays);
	relayManager.on(2);
	relayManager.display_status();

	for (size_t i = 0; i < relayManager.size(); i++) {
		cout << "turned off relay " << i << endl;
		relayManager.off(i);
		pause(50);
	}


	srand((int)time(NULL));
	int rand_delay = rand() % 5000;

	while (true) {
		if (main.over(rand_delay)) {

		}
	}

	cin.get();
	return 0;
}