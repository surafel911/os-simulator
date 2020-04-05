#include <os-simulator/driver.h>

#include <stdbool.h>

#include <os-simulator/memory.h>

void
driver_init(void)
{
	memory_init();
}

bool
driver_running(void)
{
	return false;
}

void
driver_cycle(void)
{
}

void
driver_quit(void)
{
}
