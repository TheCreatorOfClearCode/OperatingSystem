#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"

void clear_command(const char *args)
{
    vga_clear();
}

void clear_init()
{
    register_command("clear", clear_command, "Clears the screen");
}