Setup is two raspberry pico 1's (RP2040) where one is plugged into computer USB and running debug probe firmware, while the target has its power, SWD debug, and UART connected to the debugger probe.

This test program is to just make sure that the target pico can receive serial commands from the host computer running a serial terminal (e.g. `screen /dev/ttyACM0 115200`).
