#include "init/start_drivers/start_drivers.h"
#include "init/start_commands/start_commands.h"
#include "../shell/shell/shell.h"
#include "drivers/VGA/vga.h"

void kernel_main()
{
    vga_write("Starting drivers...");
    start_drivers();
    vga_write("Starting modules...");
    start_commands();
    vga_write("Starting shell...");
    shell_run();
}