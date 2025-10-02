#pragma once
#include <stddef.h>

typedef struct
{
    const char *name;
    void (*func)(const char *args);
    const char *description;
} Command;

void register_command(const char *name, void (*func)(const char *args), const char *description);
void execute_command(const char *buf);

extern Command commands[];
extern size_t command_count;