#ifndef CLASS_BUTTON
#define CLASS_BUTTON

#include "Arduino.h"

class Button{
	private:
		int PIN;
		void IRAM_ATTR isr();

	public:
		Button(int button_pin){
			PIN = button_pin;
			attachInterrupt(PIN, isr, FALLING);
		}
};

#endif