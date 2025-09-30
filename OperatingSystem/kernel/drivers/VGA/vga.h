#pragma once
#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

enum vga_color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

void vga_init();

void vga_setcolor(uint8_t fg, uint8_t bg);

void vga_putc(char c);
void vga_write(const char *s);
void vga_write_color(const char *s, uint8_t fg, uint8_t bg);

void vga_clear();

void move_cursor();
void vga_enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void vga_disable_cursor();

uint8_t vga_getcolor();
size_t vga_get_row();
size_t vga_get_col();
void vga_set_row_col(size_t r, size_t c);
void vga_clear_char_at(size_t r, size_t c);