#include "commands_config.h"
#include "../../../../shell/commands_execute/commands_execute.h"

extern void about_init();
extern void help_init();
extern void clear_init();
extern void poweroff_init();
extern void reboot_init();
extern void datetime_init();

CommandsConfig command_modules[] = {
    {"Command: about", about_init},
    {"Command: help", help_init},
    {"Command: clear", clear_init},
    {"Command: poweroff", poweroff_init},
    {"Commands: reboot", reboot_init},
    {"Commands: date&time", datetime_init}
};

int command_modules_count = sizeof(command_modules) / sizeof(command_modules[0]);