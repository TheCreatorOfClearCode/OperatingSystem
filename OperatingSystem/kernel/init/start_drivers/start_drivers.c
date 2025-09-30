#include "start_drivers.h"
#include "../configs/drivers_config/drivers_config.h"
#include "../../drivers/VGA/vga.h"
#include "../../drivers/keyboard/keyboard.h"

void start_drivers()
{
    for (int i = 0; i < drivers_count; i++)
    {
        vga_write("Starting driver: ");
        vga_write(drivers[i].name);
        vga_putc('\n');
        drivers[i].init();
    }
}
