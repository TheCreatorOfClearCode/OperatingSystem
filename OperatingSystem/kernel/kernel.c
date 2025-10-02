#include "init/start_drivers/start_drivers.h"
#include "init/start_commands/start_commands.h"
#include "../shell/shell/shell.h"
#include "drivers/VGA/vga.h"

void kernel_main()
{
    vga_write_color("=== Starting system... ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting drivers...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    start_drivers();
    vga_write_color("=> Drivers initialized\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting command modules...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    start_commands();
    vga_write_color("=> Command modules initialized\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting shell...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    shell_run();
}