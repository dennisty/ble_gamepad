#include "bt_stack_setup_lib.h"
#include "gamepad_advertisement_lib.h"
#include "gamepad_device_information_lib.h"

static void bt_packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size)
{
    UNUSED(channel);
    UNUSED(size);

    if (packet_type != HCI_EVENT_PACKET)
    {
        return;
    }

    switch (hci_event_packet_get_type(packet))
    {
    case BTSTACK_EVENT_STATE:
        if (btstack_event_state_get_state(packet) == HCI_STATE_WORKING)
        {
            printf("BLE stack initialized, starting advertising...\n");

            // TODO: Add bt start advertising function
        }
        break;
    default:
        break;
    }
}

int8_t setup_bluetooth(uint8_t const profile_data[])
{
    if (cyw43_arch_init())
    {
        printf("Failed to initialize CYW43 architecture\n");
        return -1;
    }
    else
    {
        printf("Successfully initialized CYW43 architecture\n");
    }

    l2cap_init();
    sm_init();

    att_server_init(profile_data, NULL, NULL);

    // TODO: Mocking this value until hardware implementation is done
    battery_service_server_init(42);

    set_device_information();

    hci_event_callback_registration.callback = &bt_packet_handler;
    hci_add_event_handler(&hci_event_callback_registration);

    // Turn on Bluetooth
    if (hci_power_control(HCI_POWER_ON))
    {
        printf("Error occurred when powering on Bluetooth\n");
        return -1;
    }
}