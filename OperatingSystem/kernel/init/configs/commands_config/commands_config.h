#pragma once

typedef void (*command_func_t)();

typedef struct
{
    const char *name;
    command_func_t init;
} CommandsConfig;

extern CommandsConfig commands[];
extern int commands_count;