#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"

void help_command(const char* args) {
    vga_write("Available commands: about, help, clear\n");
}

void help_init() {
    register_command("help", help_command);
}