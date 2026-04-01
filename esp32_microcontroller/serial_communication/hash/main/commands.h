#ifndef COMMANDS_H
#define COMMANDS_H

/*  pins for LEDS to control  */
#define PIN_RED     25
#define PIN_YELLOW  26
#define PIN_GREEN   27

/*  commands for LED control and other stuff
*   NOTE:
*
*   These commands below are hashed values and
*   may differ on your system. To figure out which
*   hashed value returns, use the internal function
*   _test_commands_to_hash() with your desired
*   command expression as a (C)-String.
*/
#define CMD_RED_ON      0x1927401c                //  red_on
#define CMD_RED_OFF     0x3e0f42fa                //  red_off
#define CMD_YELLOW_ON   0xb4813a1d                //  yellow_on
#define CMD_YELLOW_OFF  0x44a87d1b                //  yellow_off
#define CMD_GREEN_ON    0xc499a572                //  green_on
#define CMD_GREEN_OFF   0x57ce5310                //  green_off
#define CMD_SYSTEM_INFO 0x82b7d7f5                //  system_info

/*  function prototypes */
void collect_system_informations(void);           //  when "system_info" has been typed in
void handler_led_red_on(void);                    //  turn on red LED
void handler_led_red_off(void);                   //  turn off red LED
void handler_led_yellow_on(void);
void handler_led_yellow_off(void);
void handler_led_green_on(void);
void handler_led_green_off(void);
void handle_incoming_signals(void);               //  handle the incoming signal by UART
uint32_t convert_to_hash_string(const char *expr);//  convert the incoming message into a hashed value

#endif