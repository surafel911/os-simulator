#ifndef OS_SIMULATOR_REGISTER_H
#define OS_SIMULATOR_REGISTER_H

#include <stdint.h>

enum register_id {
	REG_ACC,
	REG_ZERO,
	CPU_REG_R3,
	CPU_REG_R4,
	CPU_REG_R5,
	CPU_REG_R6,
	CPU_REG_R7,
	CPU_REG_R8,
	CPU_REG_R9,
	CPU_REG_R10,
	CPU_REG_R11,
	CPU_REG_R12,
	CPU_REG_R13,
	CPU_REG_R14,
	CPU_REG_R15,
	CPU_REG_R16,
};

struct registers {
	int32_t registers[15];
};

int32_t
reg_get(struct* registers reg, enum register_id id);

void
reg_set(struct registers reg, enum register_id id, int32_t v);

#endif  // OS_SIMULATOR_REGISTER_H
