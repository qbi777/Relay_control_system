const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4; // Pushbutton pins
const int relayPin1 = 13;
const int relayPin2 = 12;
const int relayPin3 = 11; // Relay control pins

// Relay states
bool relayState1 = false;
bool relayState2 = false;
bool relayState3 = false;

// Timer variables
unsigned long relay1Time = 0;
unsigned long relay2Time = 0;
unsigned long relay3Time = 0;
const unsigned long relayOpenTime = 30000; // 5 minutes in milliseconds

// Special condition flags
bool relay1Welded = false;
bool relay2Welded = false;
bool relay3Welded = false;

void setup() {
  Serial.begin(9600);

  // Initialize relay pins as outputs
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  
  // Initialize button pins as inputs with internal pull-up resistors
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  // Start with all relays open
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  digitalWrite(relayPin3, LOW);
}

void loop() {
  // Read the state of the pushbuttons
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);

  // Control Relay1 based on button1 state
  if (buttonState1 == LOW && !relayState1) { // Button pressed and relay is off
    digitalWrite(relayPin1, HIGH); // Activate Relay1
    relayState1 = true; // Update state
    relay1Time = millis(); // Start timer
  }

  // Control Relay2 based on button2 state
  if (buttonState2 == LOW && !relayState2) { // Button pressed and relay is off
    digitalWrite(relayPin2, HIGH); // Activate Relay2
    relayState2 = true; // Update state
    relay2Time = millis(); // Start timer
  }

  // Control Relay3 based on button3 state
  if (buttonState3 == LOW && !relayState3) { // Button pressed and relay is off
    digitalWrite(relayPin3, HIGH); // Activate Relay3
    relayState3 = true; // Update state
    relay3Time = millis(); // Start timer
  }

  // Check if relays should be opened after 5 minutes
  if (relayState1 && (millis() - relay1Time >= relayOpenTime)) {
    digitalWrite(relayPin1, LOW); // Deactivate Relay1
    relayState1 = false; // Update state
  }

  if (relayState2 && (millis() - relay2Time >= relayOpenTime)) {
    digitalWrite(relayPin2, LOW); // Deactivate Relay2
    relayState2 = false; // Update state
  }

  if (relayState3 && (millis() - relay3Time >= relayOpenTime)) {
    digitalWrite(relayPin3, LOW); // Deactivate Relay3
    relayState3 = false; // Update state
  }

  // Check for special conditions
  checkSpecialConditions();

  // Status Monitoring
  monitorRelayStatus();
}

void checkSpecialConditions() {
  // Example checks for welded conditions
  if (relayState1 && (millis() - relay1Time >= relayOpenTime * 2)) { // Check if it has been closed too long
    relay1Welded = true; // Mark as welded
  } else {
    relay1Welded = false; // Reset if it was opened properly
  }

  if (relayState2 && (millis() - relay2Time >= relayOpenTime * 2)) {
    relay2Welded = true;
  } else {
    relay2Welded = false;
  }

  if (relayState3 && (millis() - relay3Time >= relayOpenTime * 2)) {
    relay3Welded = true;
  } else {
    relay3Welded = false;
  }
}

void monitorRelayStatus() {
  Serial.print("Relay 1: ");
  Serial.print(relayState1 ? "Closed" : "Open");
  Serial.print(" | Error Status: ");
  Serial.println(relay1Welded ? "Welded" : "No Error");

  Serial.print("Relay 2: ");
  Serial.print(relayState2 ? "Closed" : "Open");
  Serial.print(" | Error Status: ");
  Serial.println(relay2Welded ? "Welded" : "No Error");

  Serial.print("Relay 3: ");
  Serial.print(relayState3 ? "Closed" : "Open");
  Serial.print(" | Error Status: ");
  Serial.println(relay3Welded ? "Welded" : "No Error");
}
