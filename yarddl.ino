const String SPLASH = "YARDDL:\n Yet Another Really Dumb Data Logger";
const int apins[4] = {18, 19, 20, 21};

int readTime = 0;
int mode = 0; // 0 idle, 1 reading // moar?
int incomingByte = 0;

String command = "";


void setup() {
  //
  Serial.begin(9600);
}

void loop() {

  if (mode == 1) {
    for (int i = 0; i < sizeof(apins) / sizeof(int); i++) {
      if (i > 0) Serial.print(",");
      Serial.print(analogRead(apins[i]));
    }
    Serial.print("\n");
  }

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte != 10) {
      command += char(incomingByte);
    }
    else {
      if (command == "read") {
        mode = 1;
      }
      else if (command == "stop") {
        mode = 0;
      }
      command = "";
    }
 }

 
  delay(100);
}

void menu() {
  Serial.print(SPLASH);
  Serial.print("\nHow long would you like to read data for? (0 for no limit)");
}

