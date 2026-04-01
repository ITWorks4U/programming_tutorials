#define SERIAL_BAUD_RATE  115200
#define PIN_BUTTON        12
#define PIN_LED           13
#define DEBOUNCE_DELAY    50

int button_counter = 0;

int actor_state = LOW;
int current_button_state = LOW;
int last_button_state = LOW;

unsigned long last_debounce_time = 0;

void check_pressed_button_primitive() {
  button_counter += digitalRead(PIN_BUTTON);

  if (button_counter % 2 == 1) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}

void check_pressed_button_correct() {
  int reading = digitalRead(PIN_BUTTON);

  if (reading != last_button_state) {
    last_debounce_time = millis();
  }

  if ((millis() - last_debounce_time) > DEBOUNCE_DELAY) {
    if (reading != current_button_state) {
      current_button_state = reading;

      if (current_button_state == HIGH) {
        actor_state = !actor_state;
      }
    }
  }

  digitalWrite(PIN_LED, actor_state);
  last_button_state = reading;
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // check_pressed_button_primitive();
  check_pressed_button_correct();
}