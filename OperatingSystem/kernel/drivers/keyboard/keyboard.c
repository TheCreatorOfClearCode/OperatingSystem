#include "keyboard.h"
#include "../IO/io.h"

static uint8_t capslock = 0;
static uint8_t shift_pressed = 0;

static const char scancode_table[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static const char shift_table[128] = {
    0, 27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0,
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', 0, '|',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, '*', 0, ' ',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char keyboard_getchar()
{
    char c = 0;
    while (c == 0)
    {
        if (inb(0x64) & 1)
        {
            uint8_t sc = inb(0x60);

            if (sc == 0x2A || sc == 0x36)
                shift_pressed = 1;
            else if (sc == 0xAA || sc == 0xB6)
                shift_pressed = 0;

            else if (sc == 0x3A)
            {
                capslock ^= 1;
            }
            else if (sc == 0x0E)
            {
                c = '\b';
            }
            else if (sc < 128)
            {
                char base = scancode_table[sc];
                char shifted = shift_table[sc];

                if ((capslock && base >= 'a' && base <= 'z') || shift_pressed)
                {
                    c = shifted ? shifted : base;
                }
                else
                {
                    c = base;
                }
            }
        }
    }
    return c;
}

void keyboard_init()
{
}