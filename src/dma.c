#include <os-simulator/dma.h>

#include <stdint.h>

#include <os-simulator/storage.h>

void
dma_read(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words)
{
	if (channel == DMA_RAM_CHANNEL) {
		for (int i = 0; i < words; i++) {
			buffer[i] = storage_ram_get(addr + i);
		}
	} else {
		for (int i = 0; i < words; i++) {
			buffer[i] = storage_disk_get(addr + i);
		}
	}
}

void
dma_write(enum dma_channel channel, uint16_t addr,
	uint32_t* buffer, size_t words)
{
	if (channel == DMA_RAM_CHANNEL) {
		for (int i = 0; i < words; i++) {
			storage_ram_set(addr + i, buffer[i]);
		}
	} else {
		for (int i = 0; i < words; i++) {
			storage_disk_set(addr + i, buffer[i]);
		}
	}
}

void
dma_transfer(enum dma_channel dest, enum dma_channel src,
	uint16_t dest_addr, uint16_t src_addr, size_t words)
{
	if (dest == DMA_RAM_CHANNEL) {
		if (src == DMA_RAM_CHANNEL) {
			for (int i = 0; i < words; i++) {
				storage_ram_set(dest_addr + i, storage_ram_get(src_addr + i));
			}
		} else {
			for (int i = 0; i < words; i++) {
				storage_ram_set(dest_addr + i, storage_disk_get(src_addr + i));
			}
		}
	} else {
		if (src == DMA_RAM_CHANNEL) {
			for (int i = 0; i < words; i++) {
				storage_disk_set(dest_addr + i, storage_ram_get(src_addr + i));
			}
		} else {
			for (int i = 0; i < words; i++) {
				storage_disk_set(dest_addr + i, storage_disk_get(src_addr + i));
			}
		}
	}
}
