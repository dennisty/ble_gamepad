#include <stdio.h>
#include "pico/stdlib.h"
#include "bt_stack_setup_lib.h"
#include "gamepad_advertisement_lib.h"
#include "ble_gamepad.h"

extern uint8_t const profile_data[];

int main()
{
    stdio_init_all();
    sleep_ms(5000);

    if (setup_bluetooth(profile_data))
    {
        printf("Failed to setup Bluetooth! Aborting...");
        return -1;
    }

    begin_gamepad_advertisement();

    while (true)
    {
        sleep_ms(1000);
    }
}
