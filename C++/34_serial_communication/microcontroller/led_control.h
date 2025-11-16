#ifndef LED_CONTROL_H
#define LED_CONTROL_H

/*  constants */
#define PIN_GREEN   27
#define PIN_YELLOW  26
#define PIN_RED     25
#define FLAG_LED    "led_"
#define GREEN_ON    "led_green_on"
#define GREEN_OFF   "led_green_off"
#define YELLOW_ON   "led_yellow_on"
#define YELLOW_OFF  "led_yellow_off"
#define RED_ON      "led_red_on"
#define RED_OFF     "led_red_off"

/*  function prototypes */

//  Turn on or off a LED by given command.
//
//  command:
//  - the command to use
void trigger_led(String command);

#endif