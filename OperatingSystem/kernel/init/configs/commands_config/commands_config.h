#pragma once

typedef void (*command_func_t)();

typedef struct
{
    const char *name;
    command_func_t init;
} CommandsConfig;

extern CommandsConfig command_modules[];
extern int command_modules_count;