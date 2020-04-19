#include <os-simulator/memory.h>

#include <stdint.h>

#include <os-simulator/driver.h>

#define MEMORY_RAM_SIZE		1024
#define MEMORY_DISK_SIZE	2048

static uint32_t _ram[MEMORY_RAM_SIZE], _disk[MEMORY_DISK_SIZE];

uint32_t
memory_ram_get(uint16_t addr)
{
	if (addr > MEMORY_RAM_SIZE) {
		driver_error("RAM out of bounds access.");
	}

	return _ram[addr];
}

void
memory_ram_set(uint16_t addr, uint32_t word)
{
	if (addr > MEMORY_RAM_SIZE) {
		driver_error("RAM out of bounds access.");
	}

	_ram[addr] = word;
}

uint32_t
memory_disk_get(uint16_t addr)
{
	if (addr > MEMORY_DISK_SIZE) {
		driver_error("DISK out of bounds access.");
	}

	return _disk[addr];
}

void
memory_disk_set(uint16_t addr, uint32_t word)
{
	if (addr > MEMORY_DISK_SIZE) {
		driver_error("DISK out of bounds access.");
	}

	_disk[addr] = word;
}
