#include "../../kernel/drivers/keyboard/keyboard.h"
#include "../../kernel/drivers/VGA/vga.h"
#include "../commands_execute/commands_execute.h"
#include "../../libraries/string/string.h"

void shell_run()
{
    char buf[128];

    vga_write_color("Welcome!\n", COLOR_GREEN, COLOR_BLACK);
    vga_putc('\n');

    while (1)
    {
        vga_write(">> ");
        size_t len = 0;

        while (1)
        {
            char c = keyboard_getchar();
            if (c == '\n' || c == '\r')
            {
                buf[len] = 0;
                vga_putc('\n');
                break;
            }
            else if (c == '\b')
            {
                if (len > 0)
                {
                    len--;
                    size_t r = vga_get_row();
                    size_t c_pos = vga_get_col();

                    if (c_pos == 0 && r > 0)
                    {
                        r--;
                        c_pos = 79;
                    }
                    else
                    {
                        c_pos--;
                    }

                    vga_clear_char_at(r, c_pos);
                    vga_set_row_col(r, c_pos);
                }
            }

            else if (c && len < 127)
            {
                buf[len++] = c;
                vga_putc(c);
            }
        }

        if (len > 0)
            execute_command(buf);
    }
}