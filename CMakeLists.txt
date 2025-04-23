# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(ble_gamepad C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(ble_gamepad ble_gamepad.c )

pico_set_program_name(ble_gamepad "ble_gamepad")
pico_set_program_version(ble_gamepad "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(ble_gamepad 0)
pico_enable_stdio_usb(ble_gamepad 1)

# Add the standard library to the build
target_link_libraries(ble_gamepad
        pico_stdlib)

add_subdirectory(src)

# Add the standard include files to the build
target_include_directories(ble_gamepad PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_btstack_make_gatt_header(ble_gamepad PRIVATE "${CMAKE_CURRENT_LIST_DIR}/ble_gamepad.gatt")

# Add any user requested libraries
target_link_libraries(ble_gamepad 
        bt_stack_setup_lib
        gamepad_battery_lib
        gamepad_advertisement_lib
        gamepad_device_information_lib
        )

pico_add_extra_outputs(ble_gamepad)

