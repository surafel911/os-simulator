#ifndef OS_SIMULATOR_CPU_H
#define OS_SIMULATOR_CPU_H

#include <stdint.h>

#include <os-simulator/cpu_t.h>
#include <os-simulator/pcb.h>

int32_t
cpu_reg_get(const enum register_id reg);

void
cpu_reg_set(const enum register_id reg, const int32_t v);

/*
 Returns 0 if there is no pcb set, returns the addr of current pcb
 */
uint16_t
cpu_pcb_get(void);

/*
 Sets the pcb for the CPU to start executing off of.

 addr = address of the pcb in RAM
 */
void
cpu_pcb_set(uint16_t addr);

#endif // OS_SIMULATOR_CPU_H
