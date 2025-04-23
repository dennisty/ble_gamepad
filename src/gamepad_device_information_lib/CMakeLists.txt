add_library(gamepad_device_information_lib gamepad_device_information_lib.c)


target_include_directories(gamepad_device_information_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})


target_link_libraries(
    gamepad_device_information_lib
    pico_stdlib
    pico_btstack_ble
)