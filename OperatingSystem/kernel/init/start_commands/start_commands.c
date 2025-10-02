#include "start_commands.h"
#include "../configs/commands_config/commands_config.h"
#include "../../drivers/VGA/vga.h"

void start_commands()
{
    vga_write_color("=== Initializing commands ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    for (int i = 0; i < command_modules_count; i++)
    {
        vga_write_color("=> Loading module: ", COLOR_LIGHT_CYAN, COLOR_BLACK);
        vga_write(command_modules[i].name);
        vga_putc('\n');

        command_modules[i].init();

        vga_write_color("=> Module loaded: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
        vga_write(command_modules[i].name);
        vga_putc('\n');
    }

    vga_write_color("=== All command modules successfully initialized ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);
}