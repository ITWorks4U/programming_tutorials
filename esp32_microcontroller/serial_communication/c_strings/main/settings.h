#ifndef SETTINGS_H
#define SETTINGS_H

#define SERIAL_BAUD_RATE        57600         //  also possible:  9600, 28800, ..., 115200, ..., 230400, ...

//  NOTE: Make sure never to exceed the buffer size,
//        otherwise an undefined behavior appears.

#define MAX_BUFFER_SIZE_INPUT   14            //  estimated up to 14 bytes for the longest incoming message
#define MAX_BUFFER_SIZE_OUTPUT  140           //  estimated up to 140 bytes for the longest outgoing message

void clear_input_buffer(void);                //  not strictly required, but this ensures to clean the input message buffer
void collect_incoming_data(void);             //  collect the incoming data and store the content to the internal input_buffer

#endif