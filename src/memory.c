#include <os-simulator/memory.h>

#include <stdint.h>

#define MEMORY_RAM_SIZE		1024
#define MEMORY_DISK_SIZE	2048

static uint32_t _ram[MEMORY_RAM_SIZE], _disk[MEMORY_DISK_SIZE];

uint32_t
memory_ram_get(uint16_t addr)
{
	return _ram[addr];
}

void
memory_ram_set(uint16_t addr, uint32_t word)
{
	_ram[addr] = word;
}

uint32_t
memory_disk_get(uint16_t addr)
{
	return _disk[addr];
}

void
memory_disk_set(uint16_t addr, uint32_t word)
{
	_disk[addr] = word;
}
