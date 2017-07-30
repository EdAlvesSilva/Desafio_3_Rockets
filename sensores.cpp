#include "Arduino.h"
#include "sensores.h"

int check_SD() {
	if (digitalRead(7) == HIGH) {
		return 0;
	}
	else {
		return 1;
	}
};
