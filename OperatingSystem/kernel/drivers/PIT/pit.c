#include "pit.h"
#include "../IO/io.h"

static volatile uint32_t ticks = 0;

void pit_init()
{
    uint32_t divisor = 1193180 / PIT_FREQUENCY;

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, (divisor >> 8) & 0xFF);
}

void pit_set_frequency(uint32_t frequency)
{
    uint32_t divisor = 1193180 / frequency;

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, (divisor >> 8) & 0xFF);
}

void pit_handler()
{
    ticks++;
}

uint32_t pit_get_ticks()
{
    return ticks;
}

void pit_sleep(uint32_t milliseconds)
{
    uint32_t start = ticks;
    while (ticks - start < milliseconds)
    {
        asm volatile("hlt");
    }
}