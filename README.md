# cactusMicroESP8266Bootloader

This library is intended to be used with the cactus micro board, a board that joins an arduino micro (atmega 32U4) with an ESP8266 (ESP-03).

To flash the ESP-03 module, an "esp8266 programmer" sketch has to be uploaded to the atmega 32U4, then flash the ESP-03 module.

Usually the ESP-03 module is flashed with a precompiled firmware, the default one that is interfaced through AT commands, the espduino firmware, and so on. 

If a custom firmware for the ESP-03 module is being developed at the same time as the atmega 32U4 firmware, the process of flashing the "esp8266 programmer" sketch every time a change is made and flashing back the atmega 32U4 sketch get very tedious.

This library includes the "esp8266 programmer" code and runs it at startup, waiting for the ESP-03 module to be programmed or a configurable timeout to finish, and then jumps to the normal sketch code. This way there is no need to reflash the atmega 32U4 every time the ESP-03 need to be flashed.
