#ifndef SETTINGS_H
#define SETTINGS_H

#define SERIAL_BAUD_RATE  9600
#define MAX_BUFFER_INPUT  14
#define MAX_BUFFER_OUTPUT 140

//  collect the incoming data and
//  store the content to the internal
//  input_buffer
void collect_incoming_data(void);

#endif