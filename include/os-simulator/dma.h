#ifndef OS_SIMULATOR_DMA_H
#define OS_SIMULATOR_DMA_H

#include <stdint.h>
#include <stddef.h>

enum dma_channel {
	DMA_RAM_CHANNEL,
	DMA_DISK_CHANNEL,
};

void
dma_read(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words);

void
dma_write(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words);

void
dma_transfer(enum dma_channel dest, enum dma_channel src,
	uint16_t dest_addr, uint16_t src_addr, size_t words);

#endif // OS_SIMULATOR_DMA_H
