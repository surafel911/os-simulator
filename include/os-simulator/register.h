#ifndef OS_SIMULATOR_REGISTER_H
#define OS_SIMULATOR_REGISTER_H

#include <stdint.h>

enum register_id {
	REG_ACC,
	REG_ZERO,
	REG_R3,
	REG_R4,
	REG_R5,
	REG_R6,
	REG_R7,
	REG_R8,
	REG_R9,
	REG_R10,
	REG_R11,
	REG_R12,
	REG_R13,
	REG_R14,
	REG_R15,
	REG_R16,
};

struct registers {
	int32_t registers[15];
};

int32_t
reg_get(struct registers* reg, enum register_id id);

void
reg_set(struct registers reg, enum register_id id, int32_t v);

#endif  // OS_SIMULATOR_REGISTER_H
