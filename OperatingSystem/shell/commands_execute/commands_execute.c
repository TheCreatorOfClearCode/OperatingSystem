#include "commands_execute.h"
#include "../../kernel/drivers/VGA/vga.h"
#include "../../libraries/string/string.h"

#define MAX_COMMANDS 32
Command commands[MAX_COMMANDS];
size_t command_count = 0;

void register_command(const char *name, void (*func)(const char *args), const char *description)
{
    if (command_count < MAX_COMMANDS)
    {
        commands[command_count].name = name;
        commands[command_count].func = func;
        commands[command_count].description = description;
        command_count++;
    }
}

void execute_command(const char *buf)
{
    char cmd[32] = {0};
    const char *args = buf;
    size_t i = 0;

    while (*args && *args != ' ' && i < sizeof(cmd) - 1)
    {
        cmd[i++] = *args;
        args++;
    }
    cmd[i] = 0;

    while (*args == ' ')
        args++;

    for (size_t j = 0; j < command_count; j++)
    {
        if (!strcmp(cmd, commands[j].name))
        {
            commands[j].func(args);
            return;
        }
    }

    vga_write_color("Unknown command!\n", COLOR_RED, COLOR_BLACK);
}