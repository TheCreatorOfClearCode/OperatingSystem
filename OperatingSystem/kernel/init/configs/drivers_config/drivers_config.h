#pragma once

typedef void (*driver_func_t)();

typedef struct
{
    const char *name;
    driver_func_t init;
} DriverConfig;

extern DriverConfig drivers[];
extern int drivers_count;