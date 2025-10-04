#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"
#include "../kernel/drivers/IO/io.h"

void poweroff_command(const char *args)
{
    vga_clear();
    vga_write("Powering off...\n");

    outw(0xB004, 0x2000);
    outw(0x604, 0x2000);
    outw(0x4004, 0x3400);
    outw(0x1004, 0x2000);
    outw(0x1004, 0x3400);
    outw(0xB004, 0x2000);

    outb(0xCF9, 0x0E);

    for (volatile int i = 0; i < 10000; i++)
        ;
    vga_write_color("Poweroff failed, halting CPU...\n", COLOR_RED, COLOR_BLACK);

    __asm__ __volatile__("cli");
    for (;;)
    {
        __asm__ __volatile__("hlt");
    }
}

void poweroff_init()
{
    register_command("poweroff", poweroff_command, "Turns off the device");
}