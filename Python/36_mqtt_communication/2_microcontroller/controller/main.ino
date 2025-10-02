#include "mqtt_settings.h"
#include "pin_settings.h"

//  for serial debug only
#define BAUD_RATE   115200
static bool toggle_leds = false;

void setup() {
  /*  general settings  */
  Serial.begin(BAUD_RATE);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);

  //  turn on red LED
  digitalWrite(PIN_RED, HIGH);

  /*  DHT11 setup */
  setup_dht_sensor();

  /*  WiFi  */
  setup_wifi_connection();

  /*  MQTT  */
  setup_mqtt_connection();
}

void loop() {
  check_wifi_connection();
  launch_mqtt_connection();
}

void trigger_led_status(void) {
  toggle_leds = !toggle_leds;

  //  on true, turn on green + turn off red
  //  on false, turn on red + turn off green
  if (toggle_leds) {
    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_GREEN, HIGH);
  } else {
    digitalWrite(PIN_RED, HIGH);
    digitalWrite(PIN_GREEN, LOW);
  }
}

void endless_red_blink(void) {
  while(true) {
    digitalWrite(PIN_RED, HIGH);
    delay(1000);
    digitalWrite(PIN_RED, LOW);
    delay(1000);
  }
}