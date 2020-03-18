#ifndef OS_SIMULATOR_CPU_T_H
#define OS_SIMULATOR_CPU_T_H

#include <stdint.h>

#include <os-simulator/register.h>

struct cpu_state {
	uint16_t program_counter;
	struct registers cpu_registers;
};

#endif // OS_SIMULATOR_CPU_T_H
