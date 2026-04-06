#ifndef SETTINGS_H
#define SETTINGS_H

#define PIN_A   15
#define PIN_B   2     // NOTE: by setting this pin to HIGH, the internal led (LED_BUILDIN) will also be HIGH
#define PIN_C   4
#define PIN_D   16
#define PIN_E   17
#define PIN_F   5
#define PIN_G   18
#define PIN_DP  19    // NOTE: if you don't need the DP pin, this can also be ignored

//  ---
//  with 200 ohms resistor
//  ---

#define PIN_DIG_1 27
#define PIN_DIG_2 14
#define PIN_DIG_3 12
#define PIN_DIG_4 13

//  general definitions
#define TIMEOUT_MS        500
#define UPPER_BOUNDARY    10000

#endif