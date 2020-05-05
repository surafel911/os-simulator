#include <os-simulator/driver.h>
#include <os-simulator/driver_i.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include <os-simulator/cpu.h>
#include <os-simulator/pcb.h>
#include <os-simulator/loader.h>
#include <os-simulator/storage.h>
#include <os-simulator/scheduler.h>
#include <os-simulator/dispatcher.h>

static bool _running = true;

void
driver_init(void)
{
	scheduler_init();
}

void
driver_start(int argc, char* argv[])
{
	char* path;
	FILE* file;

	if (argc >= 2) {
		path = argv[1];
	} else {
		path = "bin/job.txt";
	}

	file = fopen(path, "r");

	loader_load_jobs_to_disk(file);

	fclose(file);
}

void
driver_cycle(void)
{
	static struct pcb pcb;

	scheduler_load_jobs();

	if (cpu_pcb_get().jcc.id == 0) {
		scheduler_schedule_job();

		dispatcher_assign_job();
	}

	cpu_execute();

	pcb = cpu_pcb_get();
	scheduler_running_pcb_set(pcb);
}

bool
driver_running(void)
{
	return _running;
}

void
driver_error(const char* format, ...)
{
	va_list args;

	va_start(args, format);

	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n\n");

	va_end(args);

	abort();
}

void
driver_signal_exit(void)
{
	_running = false;
}
