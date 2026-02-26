#include "settings.h"
#include "commands.h"

/////
/// general functions
/////

//  only for system informations
void collect_system_informations(void) {
  uint32_t max_heap_size = ESP.getHeapSize();
  uint32_t free_space_left = ESP.getFreeHeap();

  double percent = 0.0;
  if (max_heap_size > 0) {
    percent = ((double)free_space_left / (double)max_heap_size) * 100.0;
  }

  snprintf(
    output_buffer, sizeof(output_buffer),
    " #cores: %u\n core frequency: %lu MHz\n core version: %s\n model: %s\n heap size: %lu KB\n free space left: %lu KB (%.2f%%)\n",
    ESP.getChipCores(), ESP.getCpuFreqMHz(), ESP.getCoreVersion(), ESP.getChipModel(),
    max_heap_size / 1024, free_space_left / 1024, percent
  );

  Serial.println(output_buffer);
  clear_input_buffer();
}

void green_on_handler(void)  {
  digitalWrite(pin_green, HIGH);
}

void green_off_handler(void) {
  digitalWrite(pin_green, LOW);
}

void yellow_on_handler(void) {
  digitalWrite(pin_yellow, HIGH);
}

void yellow_off_handler(void) {
  digitalWrite(pin_yellow, LOW);
}

void red_on_handler(void) {
  digitalWrite(pin_red, HIGH);
}

void red_off_handler(void) {
  digitalWrite(pin_red, LOW);
}

/////
/// different implementation ways depending
/// on the used version
/////

#ifdef CURRENT_VERSION_V0                         //  string comparison
void handle_incoming_signals_v0(void) {
  /*  check, if the full command does match
  *   with one of the defined commands
  */
  if (strcmp(input_buffer, cmd_green_on) == 0) {
    green_on_handler();
  } else if (strcmp(input_buffer, cmd_green_off) == 0) {
    green_off_handler();
  } else if (strcmp(input_buffer, cmd_yellow_on) == 0) {
    yellow_on_handler();
  } else if (strcmp(input_buffer, cmd_yellow_off) == 0) {
    yellow_off_handler();
  } else if (strcmp(input_buffer, cmd_red_on) == 0) {
    red_on_handler();
  } else if (strcmp(input_buffer, cmd_red_off) == 0) {
    red_off_handler();
  } else if (strcmp(input_buffer, cmd_system_info) == 0) {
    collect_system_informations();
  }
}
#endif


#ifdef CURRENT_VERSION_V1                         //  hash value comparison
void handle_incoming_signals_v1(void) {
  // test_commands_to_hash();

  switch(convert_to_hash_string(input_buffer)) {
    case cmd_green_on:
      green_on_handler();
      break;
    case cmd_green_off:
      green_off_handler();
      break;
    case cmd_yellow_on:
      yellow_on_handler();
      break;
    case cmd_yellow_off:
      yellow_off_handler();
      break;
    case cmd_red_on:
      red_on_handler();
      break;
    case cmd_red_off:
      red_off_handler();
      break;
    case cmd_system_info:
      collect_system_informations();
      break;
  }
}

// static void test_commands_to_hash(void) {
//   Serial.println();
//   Serial.printf("green on: %lx\n", convert_to_hash_string("green_on"));
//   Serial.printf("green off: %lx\n", convert_to_hash_string("green_off"));
//   Serial.printf("yellow on: %lx\n", convert_to_hash_string("yellow_on"));
//   Serial.printf("yellow off: %lx\n", convert_to_hash_string("yellow_off"));
//   Serial.printf("red on: %lx\n", convert_to_hash_string("red_on"));
//   Serial.printf("red off: %lx\n", convert_to_hash_string("red off"));
//   Serial.printf("system info: %lx\n", convert_to_hash_string("system_info"));

//   while(true) {
//     delay(1);
//   }
// }

static uint32_t convert_to_hash_string(const char *expr) {
  uint32_t hash_value = 5381;
  int c = 0;

  while((c = *expr++)) {
    //  hash_value * 33 + c
    hash_value = ((hash_value << 5) + hash_value) + c;
  }

  return hash_value;
}
#endif


#ifdef CURRENT_VERSION_V2                         //  hash map
void handle_incoming_signals_v2(void) {
  for(size_t i = 0; i < NBR_CMDS; i++) {
    if (strcmp(input_buffer, command_table[i].command) == 0) {
      command_table[i].handler();
      break;
    }
  }
}
#endif


#ifdef CURRENT_VERSION_V3                         //  handle with raw data
void handle_incoming_signals_v3(void) {
  if (Serial.available()) {
    switch(Serial.read()) {
      case cmd_green_on:
        green_on_handler();
        break;
      case cmd_green_off:
        green_off_handler();
        break;
      case cmd_yellow_on:
        yellow_on_handler();
        break;
      case cmd_yellow_off:
        yellow_off_handler();
        break;
      case cmd_red_on:
        red_on_handler();
        break;
      case cmd_red_off:
        red_off_handler();
        break;
      case cmd_system_info:
        collect_system_informations();
        break;
    }
  }
}
#endif