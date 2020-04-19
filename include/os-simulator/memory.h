#ifndef OS_SIMULATOR_MEMORY_H
#define OS_SIMULATOR_MEMORY_H

#include <stdint.h>

uint32_t
memory_ram_get(uint16_t addr);

void
memory_ram_set(uint16_t addr, uint32_t word);

uint32_t
memory_disk_get(uint16_t addr);

void
memory_disk_set(uint16_t addr, uint32_t word);

#endif // OS_SIMULATOR_MEMORY_H
