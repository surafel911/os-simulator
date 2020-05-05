#include <os-simulator/storage.h>

#include <stdint.h>

#include <os-simulator/driver.h>

#define MEMORY_RAM_SIZE		1024
#define MEMORY_DISK_SIZE	2048

static uint32_t _ram[MEMORY_RAM_SIZE], _disk[MEMORY_DISK_SIZE];

uint32_t
storage_ram_get(uint16_t addr)
{
	if (addr > MEMORY_RAM_SIZE) {
		driver_error("RAM out of bounds access.");
	}

	return _ram[addr];
}

void
storage_ram_set(uint16_t addr, uint32_t word)
{
	if (addr > MEMORY_RAM_SIZE) {
		driver_error("RAM out of bounds access.");
	}

	_ram[addr] = word;
}

uint32_t
storage_disk_get(uint16_t addr)
{
	if (addr > MEMORY_DISK_SIZE) {
		driver_error("DISK out of bounds access.");
	}

	return _disk[addr];
}

void
storage_disk_set(uint16_t addr, uint32_t word)
{
	if (addr > MEMORY_DISK_SIZE) {
		driver_error("DISK out of bounds access.");
	}

	_disk[addr] = word;
}
