#define MAX_VALVE_CNT 8
unsigned char VALVES[MAX_VALVE_CNT] = {1, 2, 3, 4, 5, 6, 7, 8};

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);

	for(int i=0; i<MAX_VALVE_CNT; i++) {
		pinMode(VALVES[i], OUTPUT);
	}
}

void loop() {
  	while (Serial.available() > 0) {
		char command = Serial.read();
		String cmd = String(command);

		for (int i=0; i<MAX_VALVE_CNT; i++) {
			if (VALVES[i] == cmd.toInt()) {
				digitalWrite(VALVES[i], !digitalRead(VALVES[i]));
			}
    	}
	}
}