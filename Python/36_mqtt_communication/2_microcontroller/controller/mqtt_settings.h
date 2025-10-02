#ifndef MQTT_SETTINGS_H
#define MQTT_SETTINGS_H

/*  WiFi settings */
#define WIFI_NAME   ""
#define WIFI_PASSWD ""

/*  reconnection WiFi */
//  5000ms => 5s delay in case of the
//  WiFi connection has been lost
#define DELAY_REPEAT  5000

/*  MQTT communication settings  */
#define MQTT_SERVER ""
#define MQTT_PORT   1883
#define MQTT_USER   ""
#define MQTT_PASSWD ""
#define MESSAGE_LENGTH 100

/*  MQTT channel settings */
#define MQTT_CHANNEL_LED_CONTROL  "/led/control"
#define MQTT_CHANNEL_LED_STATUS   "/led/status"
#define MQTT_CHANNEL_SENSOR_DATA  "/sensor/temperature"

/*  MQTT command settings */
#define GREEN_ON    "green_on"
#define GREEN_OFF   "green_off"
#define YELLOW_ON   "yellow_on"
#define YELLOW_OFF  "yellow_off"
#define RED_ON      "red_on"
#define RED_OFF     "red_off"

/*  function prototypes */
void setup_wifi_connection(void);
void check_wifi_connection(void);

void setup_mqtt_connection(void);
void launch_mqtt_connection(void);
void publish_sensor_data(void);
void mqtt_callback(const char *topic, byte *payload, unsigned int length);

#endif