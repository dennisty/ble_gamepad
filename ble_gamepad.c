#include <stdio.h>
#include "pico/stdlib.h"
#include "gamepad_battery_lib.h"
#include "bt_stack_setup_lib.h"
#include "gamepad_advertisement_lib.h"
#include "ble_gamepad.h"

extern uint8_t const profile_data[];

int main()
{
    stdio_init_all();

    setup_bluetooth(profile_data);

    begin_gamepad_advertisement();

    while (true)
    {
        printf("Battery level: %d\n", get_current_battery_level());
        sleep_ms(1000);
    }
}
