#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"
#include <stdint.h>

#define OS_NAME "OperatingSystem by TheCreatorOfClearCode"
#define OS_VERSION "1.0"

void about_command()
{
    vga_write_color("\n===About===\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write("OS: " OS_NAME " v" OS_VERSION "\n\n");
}

void about_init()
{
    register_command("about", about_command);
}