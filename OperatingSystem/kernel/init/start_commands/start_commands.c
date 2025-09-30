#include "start_commands.h"
#include "../configs/commands_config/commands_config.h"
#include "../../drivers/VGA/vga.h"

void start_commands()
{
    for (int i = 0; i < commands_count; i++)
    {
        vga_write("Loading module: ");
        vga_write(commands[i].name);
        vga_putc('\n');
        commands[i].init();
    }
}