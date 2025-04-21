add_library(gamepad_advertisement_lib gamepad_advertisement_lib.c)


target_include_directories(gamepad_advertisement_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})


target_link_libraries(
    gamepad_advertisement_lib
    pico_stdlib
    pico_btstack_ble
)