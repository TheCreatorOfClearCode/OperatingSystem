#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"

void help_command(const char *args)
{
    vga_write_color("\n=== Help ===\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    for (size_t i = 0; i < command_count; i++)
    {
        vga_write_color(commands[i].name, COLOR_LIGHT_GREEN, COLOR_BLACK);
        vga_write(" - ");

        vga_write_color(commands[i].description, COLOR_LIGHT_GREY, COLOR_BLACK);
        vga_putc('\n');
    }

    vga_putc('\n');
}

void help_init()
{
    register_command("help", help_command, "Show list of available commands");
}