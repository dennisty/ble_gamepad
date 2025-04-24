#ifndef GAMEPAD_HID_LIB_H
#define GAMEPAD_HID_LIB_H

#include "btstack.h"
#include "pico/stdlib.h"
#include <stdio.h>

extern const uint8_t hid_report_descriptor[];

void setup_hid_service(void);

#endif