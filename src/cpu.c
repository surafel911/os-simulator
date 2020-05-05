#include <os-simulator/cpu.h>

#include <os-simulator/cpu_t.h>
#include <os-simulator/register.h>

static struct pcb _pcb;

/*
 * TODO: The CPU should signal an exit once the job id is 0.
 */

void
cpu_execute(void)
{
	_pcb.jcc.id = 0;
}

struct pcb 
cpu_pcb_get(void)
{
	return _pcb;
}

void
cpu_pcb_set(struct pcb pcb)
{
	_pcb = pcb;
}
