#ifndef OS_SIMULATOR_REGISTER_H
#define OS_SIMULATOR_REGISTER_H

#include <stdint.h>

#define REGISTER_SIZE	15

enum register_id {
	REGISTER_ACC,
	REGISTER_ZERO,
	REGISTER_REG1,
	REGISTER_REG2,
	REGISTER_REG3,
	REGISTER_REG4,
	REGISTER_REG5,
	REGISTER_REG6,
	REGISTER_REG7,
	REGISTER_REG8,
	REGISTER_REG9,
	REGISTER_REG10,
	REGISTER_REG11,
	REGISTER_REG12,
	REGISTER_REG13,
	REGISTER_REG14,
};

void
registers_init(uint32_t registers[REGISTER_SIZE]);

uint32_t
register_get(enum register_id id, uint32_t registers[REGISTER_SIZE]);

void
register_set(enum register_id id, uint32_t registers[REGISTER_SIZE], uint32_t word);

#endif // OS_SIMULATOR_REGISTER_H
