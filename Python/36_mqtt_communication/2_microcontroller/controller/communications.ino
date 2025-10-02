#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "mqtt_settings.h"

//  10,000 ms => 10 s
#define SENSOR_UPDATE_INTERVAL  10000

//  ----------
//  static settings
//  ----------
static WiFiClient esp_client;
static PubSubClient client(esp_client);
static DHT dht_sensor(PIN_DATA_TEMP_SENSOR, DHT_TYPE);
static unsigned long last_sensor_read = 0;

// NOTE: The client_id is going to initialize in
// setup_mqtt_connection() function. This client_id
// is also required in check_wifi_connection().
static String client_id = "";

//  ----------
//  functions
//  ----------

//  one-time setup for DHT11 sensor
void setup_dht_sensor(void) {
  pinMode(PIN_POWER_TEMP_SENSOR, OUTPUT);
  digitalWrite(PIN_POWER_TEMP_SENSOR, HIGH);
  dht_sensor.begin();
  delay(1000);
}

//  one-time setup WiFi connection
void setup_wifi_connection(void) {
  WiFi.begin(WIFI_NAME, WIFI_PASSWD);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("WiFi connection to " + String(WIFI_NAME) + " established.");
}

//  one-time setup MQTT connection
void setup_mqtt_connection(void) {
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(mqtt_callback);

  client_id = "esp32-client-" + String(WiFi.macAddress());
  Serial.println("attempting to connect the client " + client_id + " to the mqtt_server: " + String(MQTT_SERVER));
  int retry_counter = 0;
  bool on_success = true;

  //  NOTE:  It seems, that the client.connected() method takes some seconds for
  //  a reconnection attempt. Unlike to wait 100ms in real time, a dot may be
  //  printed with a delay of 2-3 seconds. In summary, if in an average total time of
  //  180 seconds a MQTT connection attempt is still unsuccessful, a red LED
  //  blinks forever to mark an error.

  while (!client.connected()) {
    Serial.print(".");

    if (client.connect(client_id.c_str(), MQTT_USER, MQTT_PASSWD)) {
      Serial.println("MQTT connection established");
    } else {
      retry_counter++;
      delay(100);

      //  1 minute later and still no MQTT connection available
      if (retry_counter == 60) {
        Serial.println("\nStill unable to connect to the MQTT broker. Aborting...");
        on_success = false;
        break;
      }
    }
  }

  if (on_success) {
    trigger_led_status();
    client.subscribe(MQTT_CHANNEL_LED_CONTROL);
  } else {
    //  in that case an endless loop with an optical
    //  "LED message" is going to fire
    endless_red_blink();
  }
}

//  on runtime it may appear to lose the WiFi connection;
//  a reconnection attempt is going to do
void check_wifi_connection(void) {
  String wifi_reconnect = "";
  bool on_reconnected = false;

  if (!client.connected()) {
    trigger_led_status();

    while(!on_reconnected) {
      wifi_reconnect = "Attempting MQTT connection... ";

      if (client.connect(client_id.c_str(), MQTT_USER, MQTT_PASSWD)) {
        wifi_reconnect += "reconnected";
        on_reconnected = true;
        break;
      } else {
        wifi_reconnect += "failed, rc = " + String(client.state()) + " try again in 5 seconds...";
        on_reconnected = false;
      }

      Serial.println(wifi_reconnect);
      delay(DELAY_REPEAT);
    }

    //  reconnected to the MQTT server
    trigger_led_status();
    client.subscribe(MQTT_CHANNEL_LED_CONTROL);
  }
}

//  in loop() function listen to any incoming
//  MQTT commands and also send data from DHT11
//  by MQTT every 10 seconds
void launch_mqtt_connection(void) {
  client.loop();

  unsigned long now = millis();
  if ((now - last_sensor_read) > SENSOR_UPDATE_INTERVAL) {
    last_sensor_read = now;
    publish_sensor_data();
  }
}

//  publishing DHT11 sensor data by MQTT
void publish_sensor_data(void) {
  static float temperature = dht_sensor.readTemperature();
  static float humidity = dht_sensor.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  String dht11_sensor_data = "{" + String(temperature) + " °C," + String(humidity) + " %}";
  client.publish(MQTT_CHANNEL_SENSOR_DATA, dht11_sensor_data.c_str());
  Serial.println("Sensor data published.");
}

//  MQTT callback function for incoming
//  MQTT commands from channel /led/control
void mqtt_callback(const char *topic, byte *payload, unsigned int length) {
  String incoming_message_header = "Message arrived in topic: " + String(topic);
  Serial.println(incoming_message_header);

  //  convert the received payload from byte pointer
  //  into a C-String 
  char msg[MESSAGE_LENGTH] = "";

  for(int i = 0; i < length; i++) {
    msg[i] = (char) payload[i];
  }

  //  terminate with '\0'
  msg[length] = '\0';

  String mqtt_message = String(msg);
  Serial.println(mqtt_message);

  String led_status = "";

  if (mqtt_message == GREEN_ON) {
    digitalWrite(PIN_GREEN, HIGH);
    led_status = "green led is ON";
  }

  if (mqtt_message == GREEN_OFF) {
    digitalWrite(PIN_GREEN, LOW);
    led_status = "green led is OFF";
  }

  if (mqtt_message == YELLOW_ON) {
    digitalWrite(PIN_YELLOW, HIGH);
    led_status = "yellow led is ON";
  }

  if (mqtt_message == YELLOW_OFF) {
    digitalWrite(PIN_YELLOW, LOW);
    led_status = "yellow led is OFF";
  }

  if (mqtt_message == RED_ON) {
    digitalWrite(PIN_RED, HIGH);
    led_status = "red led is ON";
  }

  if (mqtt_message == RED_OFF) {
    digitalWrite(PIN_RED, LOW);
    led_status = "red led is OFF";
  }

  //  send the LED status by MQTT
  client.publish(MQTT_CHANNEL_LED_STATUS, led_status.c_str());
}