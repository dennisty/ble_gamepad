#ifndef BT_STACK_SETUP_LIB_H
#define BT_STACK_SETUP_LIB_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "btstack.h"
#include "pico/btstack_cyw43.h"
#include "pico/cyw43_arch.h"

// HCI Callback Registration
static btstack_packet_callback_registration_t hci_event_callback_registration;

int8_t setup_bluetooth(uint8_t const profile_data[]);

#endif