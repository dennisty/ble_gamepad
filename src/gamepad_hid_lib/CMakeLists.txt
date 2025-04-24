add_library(gamepad_hid_lib gamepad_hid_lib.c)

target_include_directories(gamepad_hid_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

target_link_libraries(
    gamepad_hid_lib
    pico_stdlib
    pico_btstack_ble
)