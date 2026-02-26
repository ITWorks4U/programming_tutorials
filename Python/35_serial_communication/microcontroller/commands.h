#ifndef COMMANDS_H
#define COMMANDS_H

/*  version 0..3  */
#define CURRENT_VERSION_V0

/*  pins for LEDs */
#define pin_green       27
#define pin_yellow      26
#define pin_red         25

/*  commands for LEDs */
#define cmd_green_on    "green_on"
#define cmd_green_off   "green_off"
#define cmd_yellow_on   "yellow_on"
#define cmd_yellow_off  "yellow_off"
#define cmd_red_on      "red_on"
#define cmd_red_off     "red_off"

/*  command for system info */
#define cmd_system_info "system_info"

/*  function prototypes and other settings */
void collect_system_informations(void);
void green_on_handler(void);
void green_off_handler(void);
void yellow_on_handler(void);
void yellow_off_handler(void);
void red_on_handler(void);
void red_off_handler(void);

/////
/// different implementation ways depending
/// on the used version
/////

#ifdef CURRENT_VERSION_V0                         //  string comparison
void handle_incoming_signals_v0(void);
#endif

#ifdef CURRENT_VERSION_V1                         //  hash value comparison

#undef cmd_green_on
#undef cmd_green_off
#undef cmd_yellow_on
#undef cmd_yellow_off
#undef cmd_red_on
#undef cmd_red_off
#undef cmd_system_info

//  NOTE: the hash values might differ
//        on an another system
#define cmd_green_on    0xc499a572
#define cmd_green_off   0x57ce5310
#define cmd_yellow_on   0xb4813a1d
#define cmd_yellow_off  0x44a87d1b
#define cmd_red_on      0x1927401c
#define cmd_red_off     0x3e0f42fa
#define cmd_system_info 0x82b7d7f5

void handle_incoming_signals_v1(void);
#endif

#ifdef CURRENT_VERSION_V2                         //  hash map
typedef void (*command_handler_t)(void);

typedef struct {
  const char *command;
  command_handler_t handler;
} CommandHandler;

void handle_incoming_signals_v2(void);
#endif

#ifdef CURRENT_VERSION_V3                         //  handle with raw data

#undef cmd_green_on
#undef cmd_green_off
#undef cmd_yellow_on
#undef cmd_yellow_off
#undef cmd_red_on
#undef cmd_red_off
#undef cmd_system_info

//  NOTE: these are customized expressions
#define cmd_green_on    0x01
#define cmd_green_off   0x02
#define cmd_yellow_on   0x03
#define cmd_yellow_off  0x04
#define cmd_red_on      0x05
#define cmd_red_off     0x06
#define cmd_system_info 0xA4

void handle_incoming_signals_v3(void);
#endif

#endif