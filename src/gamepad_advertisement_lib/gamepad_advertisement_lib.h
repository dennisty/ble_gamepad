#ifndef GAMEPAD_ADVERTISEMENT_LIB
#define GAMEPAD_ADVERTISEMENT_LIB

#include "btstack.h"
#include "pico/stdlib.h"

static uint8_t adv_data[] = {
    // Flags: General Discoverable Mode
    0x02,
    BLUETOOTH_DATA_TYPE_FLAGS,
    0x06,
    // Name
    0x0B,
    BLUETOOTH_DATA_TYPE_COMPLETE_LOCAL_NAME,
    'G',
    'a',
    'm',
    'e',
    'p',
    'a',
    'd',
    'B',
    'L',
    'E',
    // Service UUIDs (HID over GATT)
    0x07,
    BLUETOOTH_DATA_TYPE_COMPLETE_LIST_OF_16_BIT_SERVICE_CLASS_UUIDS,
    0x12, // HID
    0x18,
    0x0F, // Battery
    0x18,
    0x0A, // Device Information
    0x18,
    // Appearance Value (HID - Gamepad)
    0x03,
    BLUETOOTH_DATA_TYPE_APPEARANCE,
    0xC4,
    0x03,
};
void begin_gamepad_advertisement(void);

#endif