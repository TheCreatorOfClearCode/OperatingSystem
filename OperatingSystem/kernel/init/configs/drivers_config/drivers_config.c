#include "drivers_config.h"
#include "../../../drivers/VGA/vga.h"
#include "../../../drivers/keyboard/keyboard.h"
#include "../../../drivers/RTC/rtc.h"

DriverConfig drivers[] = {
    {"VGA Driver", vga_init},
    {"Keyboard Driver", keyboard_init},
    {"Real Time Clock Driver", rtc_init}
};

int drivers_count = sizeof(drivers) / sizeof(drivers[0]);