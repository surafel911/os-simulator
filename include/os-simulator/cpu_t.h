#ifndef OS_SIMULATOR_CPU_T_H
#define OS_SIMULATOR_CPU_T_H

#include <stdint.h>

#include <os-simulator/register.h>

struct cpu_state {
	uint16_t program_counter;
	struct registers registers;
};

#endif // OS_SIMUALTOR_CPU_T_H
