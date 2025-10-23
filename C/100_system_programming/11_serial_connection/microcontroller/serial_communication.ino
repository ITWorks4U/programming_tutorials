#define PIN_LED_POWER           13              //  pin out for LED
#define COMMAND_ON              "led_on"        //  turn on command
#define COMMAND_OFF             "led_off"       //  turn off command

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED_POWER, OUTPUT);
}

void loop() {
  String incoming_command = Serial.readStringUntil('\n');

  if (incoming_command.equals(COMMAND_ON)) {
    digitalWrite(PIN_LED_POWER, HIGH);
    Serial.write("LED is ON\n");
    Serial.flush();
  } else if (incoming_command.equals(COMMAND_OFF)) {
    digitalWrite(PIN_LED_POWER, LOW);
    Serial.write("LED is OFF\n");
    Serial.flush();
  }
}
