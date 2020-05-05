#include <os-simulator/dispatcher.h>

#include <os-simulator/cpu.h>
#include <os-simulator/cpu_t.h>
#include <os-simulator/pcb.h>
#include <os-simulator/scheduler.h>

void
dispatcher_assign_job(void)
{
	struct pcb pcb;

	pcb = scheduler_running_pcb_get();
	cpu_pcb_set(pcb);
}
