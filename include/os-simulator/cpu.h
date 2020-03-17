#ifndef OS_SIMULATOR_CPU_H
#define OS_SIMULATOR_CPU_H

#include <stdint.h>

#include <os-simulator/register.h>

struct cpu_state {
	int32_t* program_counter;
	struct registers cpu_registers;
};

int32_t
cpu_reg_get(const enum cpu_register reg);

void
cpu_reg_set(const enum cpu_register reg, const int32_t v);

struct cpu_state
cpu_state_get(void);

#endif // OS_SIMULATOR_CPU_H
