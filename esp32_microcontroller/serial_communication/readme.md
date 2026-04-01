#   Serial communication (UART)

-   send and receive messages by UART connection with any other device, like a PC
-   offers to handle the message transport with:
    -   strings C++
    -   C-strings
    -   hashed value
    -   hash map
    -   raw data

>   **NOTE**:   Make sure, that the BAUDRATE on both systems **must** be idendical, otherwise you'll receive or send any garbage.

### specifications

| implementation | note | additional informations | recommendation |
| - | - | - | - |
| strings with C++ | easy to implement and understand | horribly slow | should not be used |
| strings with C | harder to implement than strings in C++ | you should know how many characters can be handled, otherwise an undefined behavior is the result | if you really need a clean word transmission and command handling, this can be used |
| hashed value | extremly fast than C-strings | The message might still be transmitted as a string and this should be converted before into a hashed value. The comparison works really fast. | are prefered in use |
| hash map | a bit "slower" than the raw hashed value | This looks more professional and may handle additional settings. If the incoming message is still a string, then this shall be translated into its correct hashed value. | are prefered in use |
| raw data | the fastest way | The incoming and outgoing data are hexadecimal values and can be used for anything, as long as, the messages are numeric. It depends on you how to handle the raw data. | are typically in use for real time scenarios |

### examples
####    strings with C++:
```
String incomingMessage;

void handle_incoming_signals(void) {
  if (incomingMessage.equals("")) {
    // action 1
  } else if (incomingMessage.equals("")) {
    // action 2
  }

  // and so on
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  incomingMessage = Serial.readStringUntil('\n');
  handle_incoming_signals();
}

```

####    strings with C:
```
char incomingMessage[CERTAIN_BUFFER_SIZE_HERE + 1];

void handle_incoming_signals(void) {
  if (strcmp(incomingMessage, "") == 0) {
    // action 1
  } else if (strcmp(incomingMessage, "") == 0) {
    // action 2
  }

  // and so on
}

void collect_incoming_data(void) {
  static int counter = 0;
  
  while (Serial.available()) {
    char c = (char) Serial.read();

    if (c == '\n' || c == '\r') {
      if (counter == 0) {                             //  no message received
        return;
      }

      input_buffer[counter] = '\0';                   //  replace '\n' or '\r' with '\0'
      counter = 0;
    } else {
      if (counter < CERTAIN_BUFFER_SIZE_HERE) {       //  no more than the upper buffer size of characters can be stored
        input_buffer[counter++] = c;                  //  every remaining character is going to ignore
      }
    }
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  collect_incoming_data();
  handle_incoming_signals();
}
```