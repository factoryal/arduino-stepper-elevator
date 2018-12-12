#include "Elevator.h"
#include "pin_configuration.h"

Elevator elevator(PIN_STEP, PIN_DIR, PIN_ENDSTOP);

void setup() {
	Serial.begin(115200);

 pinMode(PIN_STEP, 1);
 pinMode(PIN_DIR, 1);
	
}

void loop() {
	if (Serial.available()) {
		int n = Serial.parseInt();
		elevator.setFloor(n);
	}

}
