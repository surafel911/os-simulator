#ifndef OS_SIMULATOR_PCB_H
#define OS_SIMULATOR_PCB_H

#include <stdint.h>
#include <stdbool.h>

#include <os-simulator/cpu_t.h>

struct jcc {
	uint16_t id, size, priority;
};

struct pcb {
	uint16_t base_addr;
	struct jcc jcc;

	struct cpu_state cpu_state;
};

void
pcb_init(struct pcb* pcb);

#endif // OS_SIMULATOR_PCB_H
