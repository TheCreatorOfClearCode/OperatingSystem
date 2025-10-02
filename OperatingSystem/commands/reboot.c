#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"
#include "../kernel/drivers/IO/io.h"

void reboot_command(const char *args)
{
    vga_clear();
    vga_write("Rebooting...\n");

    outb(0x64, 0xFE);

    for (;;)
    {
        __asm__ __volatile__("hlt");
    }
}

void reboot_init()
{
    register_command("reboot", reboot_command, "Restarts the device");
}