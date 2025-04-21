add_library(bt_stack_setup_lib bt_stack_setup_lib.c)

target_include_directories(bt_stack_setup_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

target_link_libraries(
    bt_stack_setup_lib
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    gamepad_advertisement_lib
    )