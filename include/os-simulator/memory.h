#ifndef OS_SIMULATOR_MEMORY_H
#define OS_SIMULATOR_MEMORY_H

#include <stdint.h>

/*
 Initializes memory module
 */
void
memory_init(void);

/*
 How processes get memory from RAM
 */
int32_t
ram_get_addr(const int32_t addr);

/*
 How processes set memory to RAM
 */
void
ram_set_addr(const int32_t addr, const int32_t v);

/*
 Pointer to internal RAM buffer for streaming data
 */
int32_t*
ram_get_buff(void);

/*
 Pointer to internal disk buffer for streaming data
 */
int32_t*
disk_get_buff(void);

#endif //OS_SIMULATOR_MEMORY_H
