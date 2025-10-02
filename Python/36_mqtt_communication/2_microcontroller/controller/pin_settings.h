#ifndef PIN_SETTINGS_H
#define PIN_SETTINGS_H

/*  pins for LEDs */
#define PIN_GREEN   25
#define PIN_YELLOW  26
#define PIN_RED     27

/*  pins for temperature / humidity sensor (DHT11)  */
#define PIN_DATA_TEMP_SENSOR  13
#define PIN_POWER_TEMP_SENSOR 12
#define DHT_TYPE  DHT11

//  set up DHT11 sensor
void setup_dht_sensor(void);

//  optical flag for a (un-)successful WiFi / MQTT connection
//
//  => red LED: no connection
//
//  => green LED: active connection 
void trigger_led_status(void);

//  In case of a failed MQTT connection attempt after on minute
//  (more in few minutes, caused by client.connected()),
//  the red LED blinks forever with a delay of 1s.
void endless_red_blink(void);

#endif