#include <os-simulator/dma.h>

#include <stdint.h>

#include <os-simulator/memory.h>

void
dma_read(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words)
{
	if (channel == DMA_RAM_CHANNEL) {
		for (int i = 0; i < words; i++) {
			buffer[i] = memory_ram_get(addr + i);
		}
	} else {
		for (int i = 0; i < words; i++) {
			buffer[i] = memory_disk_get(addr + i);
		}
	}
}

void
dma_write(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words)
{
	if (channel == DMA_RAM_CHANNEL) {
		for (int i = 0; i < words; i++) {
			memory_ram_set(addr + i, buffer[i]);
		}
	} else {
		for (int i = 0; i < words; i++) {
			memory_disk_set(addr + i, buffer[i]);
		}
	}
}
