const int MAX_VALVE_CNT = 8;
const int MAX_RECEIVED_LEN = 14;
const char START_COMMAND = "s";
const char END_COMMAND = "e";
unsigned char VALVES[MAX_VALVE_CNT] = {1, 2, 3, 4, 5, 6, 7, 8};

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);

	for(int i=0; i<MAX_VALVE_CNT; i++) {
		pinMode(VALVES[i], OUTPUT);
	}
}

void loop() {
	static String receivedString = ""; 
	static String activePK = "";

  	while (Serial.available() > 0) {
        char incomingChar = Serial.read();
        
        if (incomingChar == "\n") {
            receivedString = "";
        } else {
            receivedString += incomingChar;
        }

		if (receivedString.length() == MAX_RECEIVED_LEN) {
			int index_1 = receivedString.indexOf(":");
			int index_2 = receivedString.length();
			String pk = receivedString.substring(0, index_1);
			String cmd = receivedString.substring(index_1 + 1, index_2);

			if (cmd == START_COMMAND && activePK == "") {
				activePK = pk;
			} else if (cmd == END_COMMAND) {
				activePK = "";
			}

			if (activePK == pk) {
				Serial.print("1");

				for (int i=0; i<MAX_VALVE_CNT; i++) {
					if (VALVES[i] == cmd.toInt()) {
						digitalWrite(VALVES[i], !digitalRead(VALVES[i]));
					}
				}
			} else {
				Serial.print("0");
			}
		}
    }
}