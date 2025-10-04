#include "init/start_drivers/start_drivers.h"
#include "init/start_commands/start_commands.h"
#include "../shell/shell/shell.h"
#include "drivers/VGA/vga.h"
#include "multiboot.h"

multiboot_info_t *mb_info = 0;
uint32_t total_memory_mb = 0;

void kernel_main(uint32_t magic, uint32_t addr)
{
    if (magic != 0x2BADB002)
    {
        return;
    }

    mb_info = (multiboot_info_t *)addr;

    if (mb_info->flags & 0x001)
    {
        total_memory_mb = (mb_info->mem_lower + mb_info->mem_upper) / 1024;
    }

    vga_write_color("=== Starting system... ===\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting drivers...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    start_drivers();
    vga_write_color("=== Drivers initialized! ===\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting command modules...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    start_commands();
    vga_write_color("=== Command modules initialized! ===\n\n", COLOR_LIGHT_GREEN, COLOR_BLACK);

    vga_write_color("=> Starting shell...\n", COLOR_LIGHT_CYAN, COLOR_BLACK);
    vga_clear();
    shell_run();
}