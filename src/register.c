#include <os-simulator/register.h>

#include <stdint.h>

#define ARRAY_SIZE(x)	(sizeof(x)/sizeof(*x))

void
registers_init(uint32_t registers[REGISTER_SIZE])
{
	for (int i = 0; i < REGISTER_SIZE; i++) {
		registers[i] = 0;
	}
}

uint32_t
register_get(enum register_id id, uint32_t registers[REGISTER_SIZE])
{
	uint32_t val;

	switch (id) {
		case REGISTER_ZERO:
			val = 0;
			break;
		case REGISTER_ACC:
			val = registers[0];
			break;
		case REGISTER_REG2 ... REGISTER_REG15:
			val = registers[(int)id - 1];
			break;
	}

	return val;
}

void
register_set(enum register_id id, uint32_t registers[REGISTER_SIZE], uint32_t word)
{
	switch (id) {
		case REGISTER_ZERO:
			break;
		case REGISTER_ACC:
			registers[0] = word;
			break;
		case REGISTER_REG2 ... REGISTER_REG15:
			registers[(int)id - 1] = word;
			break;
	}
}
