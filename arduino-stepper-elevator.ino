#include "Elevator.h"
#include "pin_configuration.h"

Elevator elevator(PIN_STEP, PIN_DIR, PIN_ENDSTOP);

void setup() {
	Serial.begin(115200);

}

void loop() {
	if (Serial.available()) {
    if (Serial.peek() == 'd'){
      elevator.home();
      Serial.read();
    }
		else {
		  int n = Serial.parseInt();
		  elevator.setFloor(n);
		}
	}

}
