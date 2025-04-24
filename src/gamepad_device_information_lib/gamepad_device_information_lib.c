#include "gamepad_device_information_lib.h"

void setup_device_information_service(void)
{
    device_information_service_server_init();

    device_information_service_server_set_pnp_id(0x01, 0x1234, 0xABCD, 0x0100);
}