#include "vga.h"
#include "../IO/io.h"

static uint16_t *const VGA_MEMORY = (uint16_t *)0xB8000;
static size_t row = 0, col = 0;
static uint8_t color;

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t)uc | (uint16_t)color << 8;
}

static inline uint8_t vga_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

void vga_setcolor(uint8_t fg, uint8_t bg)
{
    color = vga_color(fg, bg);
}

void move_cursor()
{
    uint16_t pos = row * VGA_WIDTH + col;
    outb(0x3D4, 14);
    outb(0x3D5, pos >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, pos & 0xFF);
}

void vga_enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void vga_disable_cursor()
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

void vga_clear()
{
    for (size_t y = 0; y < VGA_HEIGHT; y++)
        for (size_t x = 0; x < VGA_WIDTH; x++)
            VGA_MEMORY[y * VGA_WIDTH + x] = vga_entry(' ', color);
    row = col = 0;
    move_cursor();
}

void scroll()
{
    if (row >= VGA_HEIGHT)
    {
        for (size_t y = 1; y < VGA_HEIGHT; y++)
            for (size_t x = 0; x < VGA_WIDTH; x++)
                VGA_MEMORY[(y - 1) * VGA_WIDTH + x] = VGA_MEMORY[y * VGA_WIDTH + x];
        for (size_t x = 0; x < VGA_WIDTH; x++)
            VGA_MEMORY[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = vga_entry(' ', color);
        row = VGA_HEIGHT - 1;
    }
}

void vga_putc(char c)
{
    if (c == '\n')
    {
        row++;
        col = 0;
    }
    else if (c == '\r')
    {
        col = 0;
    }
    else
    {
        VGA_MEMORY[row * VGA_WIDTH + col] = vga_entry(c, color);
        if (++col >= VGA_WIDTH)
        {
            col = 0;
            row++;
        }
    }
    scroll();
    move_cursor();
}

void vga_write(const char *s)
{
    for (size_t i = 0; s[i]; i++)
        vga_putc(s[i]);
}

uint8_t vga_getcolor()
{
    return color;
}

size_t vga_get_row()
{
    return row;
}

size_t vga_get_col()
{
    return col;
}

void vga_set_row_col(size_t r, size_t c)
{
    row = r;
    col = c;
    move_cursor();
}

void vga_clear_char_at(size_t r, size_t c)
{
    VGA_MEMORY[r * VGA_WIDTH + c] = vga_entry(' ', color);
}

void vga_write_color(const char *s, uint8_t fg, uint8_t bg)
{
    uint8_t old_color = vga_getcolor();
    vga_setcolor(fg, bg);
    vga_write(s);
    vga_setcolor(old_color >> 0 & 0x0F, old_color >> 4 & 0x0F);
}

void vga_init()
{
    vga_setcolor(COLOR_LIGHT_GREY, COLOR_BLACK);
    vga_clear();
    vga_enable_cursor(14, 15);
}