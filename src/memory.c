#include <os-simulator/memory.h>

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_RAM_SIZE		1024
#define MEMORY_DISK_SIZE	2048

struct memory {
	int32_t ram[MEMORY_RAM_SIZE];
	uint8_t disk[sizeof(int32_t) * MEMORY_DISK_SIZE];
};

static struct memory _memory;

static void
_ram_bounds_check(const int32_t addr)
{
	if (addr >= MEMORY_RAM_SIZE) {
		fprintf(stderr, "Out of bounds RAM access.");
		abort();
	}
}

void
memory_init(void)
{
	memset(_memory.ram, 0, sizeof(_memory.ram));
	memset(_memory.disk, 0, sizeof(_memory.disk));
}

int32_t
ram_get_addr(const int32_t addr)
{
	_ram_bounds_check(addr);

	return _memory.ram[addr];
}

void
ram_set_addr(const int32_t addr, const int32_t v)
{
	_ram_bounds_check(addr);

	_memory.ram[addr] = v;
}

int32_t*
ram_get_buff(void)
{
	return _memory.ram;
}

uint8_t*
disk_get_buff(void)
{
	return _memory.disk;
}
