#include "drivers_config.h"
#include "../../../drivers/VGA/vga.h"
#include "../../../drivers/keyboard/keyboard.h"

DriverConfig drivers[] = {
    {"VGA Driver", vga_init},
    {"Keyboard Driver", keyboard_init}
};

int drivers_count = sizeof(drivers) / sizeof(drivers[0]);