#pragma once

typedef struct
{
    const char *name;
    void (*func)(const char *args);
} Command;

void register_command(const char *name, void (*func)(const char *args));
void execute_command(const char *buf);