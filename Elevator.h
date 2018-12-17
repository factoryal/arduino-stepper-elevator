#pragma once

#include "Arduino.h"

class Elevator {
private:
	int endstop = 0;
	int step = 0;
	int dir = 0;

	int nowFloor = 0;
	int destFloor = 0;
	int nowStep = 0;
	int floorStep[5] = { 0, 1200, 2400, 3600, 4800 };
	
	void moveHeight(int dStep) {
		if (dStep > 0) {
			digitalWrite(dir, 0);
			while (dStep--) {
				digitalWrite(step, 1);
				delayMicroseconds(1000);
				digitalWrite(step, 0);
				delayMicroseconds(1000);
			}
		}
		else {
			digitalWrite(dir, 1);
			while (dStep++) {
				digitalWrite(step, 1);
				delayMicroseconds(1000);
				digitalWrite(step, 0);
				delayMicroseconds(1000);
			}
		}
	}

public:
	Elevator(int stepPin, int dirPin, int endstopPin) {
		step = stepPin;
		dir = dirPin;
		endstop = endstopPin;
    pinMode(step, 1);
    pinMode(dir, 1);
    pinMode(endstop, 2);
	}

	int getFloor() {
		return nowFloor;
	}

	void setFloor(int nFloor) {
		destFloor = nFloor;
		int dStep = floorStep[destFloor] - floorStep[nowFloor];
		moveHeight(dStep);
    nowFloor = destFloor;
	}

	void home() {
    digitalWrite(dir, 1);
		while(digitalRead(endstop)){
      digitalWrite(step, 1);
      delay(1);
      digitalWrite(step, 0);
      delay(1);
		}
	}

};
