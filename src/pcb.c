#include <os-simulator/pcb.h>

#include <string.h>

void
pcb_init(struct pcb* pcb)
{
	memset(pcb, 0, sizeof(*pcb));
}
