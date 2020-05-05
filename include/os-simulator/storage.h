#ifndef OS_SIMULATOR_STORAGE_H
#define OS_SIMULATOR_STORAGE_H

#include <stdint.h>

uint32_t
storage_ram_get(uint16_t addr);

void
storage_ram_set(uint16_t addr, uint32_t word);

uint32_t
storage_disk_get(uint16_t addr);

void
storage_disk_set(uint16_t addr, uint32_t word);

#endif // OS_SIMULATOR_STORAGE_H
