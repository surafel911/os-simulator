#ifndef	OS_SIMULATOR_CPU_H
#define OS_SIMULATOR_CPU_H

#include <os-simulator/pcb.h>

void
cpu_execute(void);

struct pcb 
cpu_pcb_get(void);

void
cpu_pcb_set(struct pcb pcb);

#endif // OS_SIMULATOR_CPU_H
