#ifndef OS_SIMULATOR_DRIVER_H
#define OS_SIMULATOR_DRIVER_H

#include <stdbool.h>

void
driver_init(void);

void
driver_start(int argc, char* argv[]);

void
driver_run(void);

void
driver_error(const char* format, ...);

#endif // OS_SIMULATOR_DRIVER_H
