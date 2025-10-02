#include "start_drivers.h"
#include "../configs/drivers_config/drivers_config.h"
#include "../../drivers/VGA/vga.h"
#include "../../drivers/keyboard/keyboard.h"

void start_drivers()
{
    vga_write_color("=== Initializing drivers ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    for (int i = 0; i < drivers_count; i++)
    {
        vga_write_color("=> Starting driver: ", COLOR_LIGHT_CYAN, COLOR_BLACK);
        vga_write(drivers[i].name);
        vga_putc('\n');

        drivers[i].init();

        vga_write_color("=> Driver started: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
        vga_write(drivers[i].name);
        vga_putc('\n');
    }

    vga_write_color("=== All drivers successfully initialized ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);
}