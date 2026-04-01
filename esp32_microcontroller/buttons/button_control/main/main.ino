#define SERIAL_BAUD_RATE  115200
#define PIN_BUTTON        12
#define PIN_LED           13

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  int button_state = digitalRead(PIN_BUTTON);

  if (button_state) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}