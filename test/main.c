#include <stdio.h>
#include <stdlib.h>

#include <os-simulator/driver.h>
#include <os-simulator/scheduler.h>

int
main(int argc, char* argv[])
{
	driver_init();

	scheduler_cycle();

	return 0;
}
