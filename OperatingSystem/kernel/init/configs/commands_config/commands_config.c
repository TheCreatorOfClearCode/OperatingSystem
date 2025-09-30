#include "commands_config.h"
#include "../../../../shell/commands_execute/commands_execute.h"

extern void about_init();
extern void help_init();
extern void clear_init();

CommandsConfig commands[] = {
    {"Command: about", about_init},
    {"Command: help", help_init},
    {"Command: clear", clear_init}
};

int commands_count = sizeof(commands) / sizeof(commands[0]);