#include "gamepad_hid_lib.h"

const uint8_t hid_report_descriptor[] = {
    0x05, 0x01, // Usage Page (Generic Desktop)
    0x09, 0x05, // Usage (Gamepad)
    0xA1, 0x01, // Collection (Application)

    // -------- Button (1 bit) --------
    0x05, 0x09, //   Usage Page (Button)
    0x19, 0x01, //   Usage Minimum (Button 1)
    0x29, 0x01, //   Usage Maximum (Button 1)
    0x15, 0x00, //   Logical Minimum (0)
    0x25, 0x01, //   Logical Maximum (1)
    0x95, 0x01, //   Report Count (1)
    0x75, 0x01, //   Report Size (1)
    0x81, 0x02, //   Input (Data, Variable, Absolute)

    // Padding to align to 1 byte
    0x95, 0x01, //   Report Count (1)
    0x75, 0x07, //   Report Size (7)
    0x81, 0x03, //   Input (Constant, Variable, Absolute) ; Padding

    // -------- Analog Stick (2 signed axes) --------
    0x05, 0x01, //   Usage Page (Generic Desktop)
    0x09, 0x30, //   Usage (X)
    0x09, 0x31, //   Usage (Y)
    0x15, 0x81, //   Logical Minimum (-127)
    0x25, 0x7F, //   Logical Maximum (127)
    0x75, 0x08, //   Report Size (8)
    0x95, 0x02, //   Report Count (2)
    0x81, 0x02, //   Input (Data, Variable, Absolute)

    0xC0 // End Collection
};

void setup_hid_service(void)
{
    hids_device_init(0x21, hid_report_descriptor, sizeof(hid_report_descriptor));
    printf("HID service initialized!\n");
}