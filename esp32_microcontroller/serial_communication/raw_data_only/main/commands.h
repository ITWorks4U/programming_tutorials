#include <stdint.h>
#ifndef COMMANDS_H
#define COMMANDS_H

/*  pins for LEDS to control  */
#define PIN_RED     25
#define PIN_YELLOW  26
#define PIN_GREEN   27

/*  commands for LED control and other stuff
*   NOTE:
*
*   These commands below are customized expressions.
*/
#define CMD_RED_ON      0x01
#define CMD_RED_OFF     0x02
#define CMD_YELLOW_ON   0x03
#define CMD_YELLOW_OFF  0x04
#define CMD_GREEN_ON    0x05
#define CMD_GREEN_OFF   0x06
#define CMD_SYSTEM_INFO 0xA0

/*  special definitions for raw data handling */
#define CMD_ID_BEGIN    0xB9                      //  a message may be a valid command, if this begins with 0xB9
#define LENGTH_INPUT_MSG 3                        //  contains: {CMD_ID_BEGIN, COMMAND, CRC-CHECKSUM}
#define LENGTH_OUTPUT   140                       //  140 bytes for outgoing C-String message
extern uint8_t message_buffer[LENGTH_INPUT_MSG];


/*  function prototypes */
void collect_system_informations(void);           //  when "system_info" has been typed in
void handler_led_red_on(void);                    //  turn on red LED
void handler_led_red_off(void);                   //  turn off red LED
void handler_led_yellow_on(void);
void handler_led_yellow_off(void);
void handler_led_green_on(void);
void handler_led_green_off(void);
void handle_incoming_single_signal(void);         //  handhe the single incoming signal by UART
void handle_incoming_signals(void);               //  handle a full message buffer
uint calculate_crc_checksum(void);                //  calculate the CRC checksum

#endif