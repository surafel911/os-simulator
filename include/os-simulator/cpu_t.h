#ifndef OS_SIMULATOR_CPU_T_H
#define OS_SIMULATOR_CPU_T_H

#include <stdint.h>

struct cpu_state {
	uint16_t program_counter, temp_buffer_addr,
		input_buffer_addr, output_buffer_addr;
	uint32_t registers[15];
};

#endif // OS_SIMULATOR_CPU_T_H
