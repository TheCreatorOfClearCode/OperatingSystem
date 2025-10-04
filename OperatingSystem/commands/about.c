#include "../shell/commands_execute/commands_execute.h"
#include "../kernel/drivers/VGA/vga.h"
#include <stdint.h>

#define OS_NAME "OperatingSystem by TheCreatorOfClearCode"
#define OS_VERSION "1.2"

extern uint32_t total_memory_mb;

static void cpuid(uint32_t code, uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d)
{
    __asm__ __volatile__(
        "cpuid"
        : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
        : "a"(code));
}

static void print_num(uint32_t n)
{
    char buf[16];
    int i = 0;
    if (n == 0)
        buf[i++] = '0';
    while (n > 0)
    {
        buf[i++] = '0' + (n % 10);
        n /= 10;
    }
    buf[i] = '\0';
    for (int j = i - 1; j >= 0; j--)
        vga_putc(buf[j]);
}

void about_command(const char *args)
{
    vga_write_color("\n===About===\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("OS: " OS_NAME " v" OS_VERSION "\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    char brand[49];
    uint32_t regs[4];
    for (int i = 0; i < 3; i++)
    {
        cpuid(0x80000002 + i, &regs[0], &regs[1], &regs[2], &regs[3]);
        ((uint32_t *)brand)[i * 4 + 0] = regs[0];
        ((uint32_t *)brand)[i * 4 + 1] = regs[1];
        ((uint32_t *)brand)[i * 4 + 2] = regs[2];
        ((uint32_t *)brand)[i * 4 + 3] = regs[3];
    }
    brand[48] = '\0';
    vga_write_color("CPU Brand: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
    vga_write(brand);
    vga_write("\n");

    uint32_t eax, ebx, ecx, edx;
    cpuid(4, &eax, &ebx, &ecx, &edx);
    uint32_t cores_per_package = ((eax >> 26) & 0x3F) + 1;
    if (cores_per_package > 0)
    {
        vga_write_color("Physical cores: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
        print_num(cores_per_package);
        vga_write("\n");
    }

    cpuid(1, &eax, &ebx, &ecx, &edx);
    uint8_t logical_cores = (ebx >> 16) & 0xFF;
    vga_write_color("Logical cores: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
    print_num(logical_cores);
    vga_write("\n");

    cpuid(0x16, &eax, &ebx, &ecx, &edx);
    if (eax != 0)
    {
        vga_write_color("Base freq: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
        print_num(eax);
        vga_write(" MHz\n");

        vga_write_color("Max freq: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
        print_num(ebx);
        vga_write(" MHz\n");
    }

    vga_write("\n");

    vga_write_color("RAM: ", COLOR_LIGHT_GREEN, COLOR_BLACK);
    print_num(total_memory_mb);
    vga_write(" MB\n\n");
}

void about_init()
{
    register_command("about", about_command, "Show information about the OS");
}