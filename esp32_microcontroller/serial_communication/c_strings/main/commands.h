#ifndef COMMANDS_H
#define COMMANDS_H

/*  pins for LEDS to control  */
#define PIN_RED     25
#define PIN_YELLOW  26
#define PIN_GREEN   27

/*  commands for LED control and other stuff
*   NOTE:
*   These commands are planned to handle with
*   strings in C++, as well as, C-strings in C.
*
*   In this scenario C-strings in C are in use.
*/
#define CMD_RED_ON      "red_on"
#define CMD_RED_OFF     "red_off"
#define CMD_YELLOW_ON   "yellow_on"
#define CMD_YELLOW_OFF  "yellow_off"
#define CMD_GREEN_ON    "green_on"
#define CMD_GREEN_OFF   "green_off"
#define CMD_SYSTEM_INFO "system_info"

/*  function prototypes */
void collect_system_informations(void);           //  when "system_info" has been typed in
void handler_led_red_on(void);                    //  turn on red LED
void handler_led_red_off(void);                   //  turn off red LED
void handler_led_yellow_on(void);
void handler_led_yellow_off(void);
void handler_led_green_on(void);
void handler_led_green_off(void);
void handle_incoming_signals(void);               //  handle the incoming signal by UART
#endif