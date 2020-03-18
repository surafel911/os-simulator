#ifndef OS_SIMULATOR_DRIVER_H
#define OS_SIMULATOR_DRIVER_H

#include <stdbool.h>

void
driver_init(void);

bool
driver_running(void);

void
driver_cycle(void);

void
driver_quit(void);

#endif // OS_SIMULATOR_DRIVER_H
