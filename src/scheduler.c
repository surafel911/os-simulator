#include <os-simulator/scheduler.h>

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <os-simulator/dma.h>
#include <os-simulator/pcb.h>
#include <os-simulator/storage.h>

#define SCHEDULER_FRAME_SIZE			48
#define SCHEDULER_INPUT_BUFFER_SIZE		20
#define SCHEDULER_TEMP_BUFFER_SIZE		12
#define SCHEDULER_OUTPUT_BUFFER_SIZE	12

#define ARRAY_SIZE(x)					(sizeof(x) / sizeof(*x))

struct scheduler {
	uint16_t job_index, loaded_jobs;
	struct pcb running_pcb, ready_pcbs[3];
};

static inline void
_scheduler_read_scheduler(struct scheduler* scheduler)
{
	dma_read(DMA_RAM_CHANNEL, 0, (uint32_t*)scheduler,
		sizeof(*scheduler)/sizeof(uint32_t));
}

static inline void
_scheduler_write_scheduler(struct scheduler* scheduler)
{
	dma_write(DMA_RAM_CHANNEL, 0, (uint32_t*)scheduler,
		sizeof(*scheduler)/sizeof(uint32_t));
}

static void
_scheduler_init(struct scheduler* scheduler)
{
	scheduler->job_index = 0;
	scheduler->loaded_jobs = 0;

	pcb_init(&scheduler->running_pcb);

	for (int i = 0; i < ARRAY_SIZE(scheduler->ready_pcbs); i++) {
		pcb_init(scheduler->ready_pcbs + i);
	}
}

static void
_scheduler_running_pcb_input_buff_set(struct pcb* running_pcb)
{
	dma_transfer(DMA_RAM_CHANNEL, DMA_RAM_CHANNEL,
		running_pcb->cpu_state.input_buffer_addr,
		running_pcb->base_addr + running_pcb->jcc.size,
		SCHEDULER_INPUT_BUFFER_SIZE);
}

static void
_scheduler_load_job(struct scheduler* scheduler, struct pcb* pcb)
{
	uint16_t disk_addr;

	disk_addr = storage_disk_get(scheduler->job_index + 1);

	pcb_init(pcb);

	pcb->jcc.id = storage_disk_get(disk_addr++);
	pcb->jcc.size = storage_disk_get(disk_addr++);
	pcb->jcc.priority = storage_disk_get(disk_addr++);

	pcb->base_addr = ((sizeof(*scheduler) / sizeof(uint32_t)) +
		SCHEDULER_INPUT_BUFFER_SIZE + SCHEDULER_TEMP_BUFFER_SIZE +
		SCHEDULER_OUTPUT_BUFFER_SIZE + 1) + (SCHEDULER_FRAME_SIZE * 
		scheduler->job_index++);

	dma_transfer(DMA_RAM_CHANNEL, DMA_DISK_CHANNEL, pcb->base_addr,
		disk_addr, pcb->jcc.size);

	disk_addr +=  pcb->jcc.size;
	dma_transfer(DMA_RAM_CHANNEL, DMA_DISK_CHANNEL, pcb->base_addr + 
		pcb->jcc.size, disk_addr, SCHEDULER_INPUT_BUFFER_SIZE);

	pcb->cpu_state.program_counter = pcb->base_addr;

	pcb->cpu_state.input_buffer_addr = sizeof(*scheduler) /
		sizeof(uint32_t) + 1;
	pcb->cpu_state.temp_buffer_addr = pcb->cpu_state.input_buffer_addr +
		SCHEDULER_INPUT_BUFFER_SIZE + 1;
	pcb->cpu_state.output_buffer_addr = pcb->cpu_state.temp_buffer_addr +
		SCHEDULER_TEMP_BUFFER_SIZE + 1;

	scheduler->loaded_jobs++;
}

void
scheduler_init(void)
{
	struct scheduler scheduler;

	_scheduler_init(&scheduler);

	_scheduler_write_scheduler(&scheduler);
}

void
scheduler_load_jobs(void)
{
	struct scheduler scheduler;

	_scheduler_read_scheduler(&scheduler);

	for (int i = scheduler.loaded_jobs;
		i < ARRAY_SIZE(scheduler.ready_pcbs); i++) {
		if (scheduler.job_index == storage_disk_get(0)) {
			break;
		}

		_scheduler_load_job(&scheduler,
			scheduler.ready_pcbs + scheduler.loaded_jobs);
	}

	_scheduler_write_scheduler(&scheduler);
}

void
scheduler_schedule_job(void)
{
	struct scheduler scheduler;

	_scheduler_read_scheduler(&scheduler);

	scheduler.running_pcb = scheduler.ready_pcbs[0];

	for (int i = 0; i < ARRAY_SIZE(scheduler.ready_pcbs) - 1; i++) {
		scheduler.ready_pcbs[i] = scheduler.ready_pcbs[i + 1];
	}

	scheduler.loaded_jobs--;
	pcb_init(scheduler.ready_pcbs + ARRAY_SIZE(scheduler.ready_pcbs) - 1);

	_scheduler_running_pcb_input_buff_set(&scheduler.running_pcb);
	_scheduler_write_scheduler(&scheduler);
}

struct pcb
scheduler_running_pcb_get(void)
{
	struct scheduler scheduler;

	_scheduler_read_scheduler(&scheduler);

	return scheduler.running_pcb;
}

void
scheduler_running_pcb_set(struct pcb pcb)
{
	struct scheduler scheduler;

	_scheduler_read_scheduler(&scheduler);

	scheduler.running_pcb = pcb;

	_scheduler_write_scheduler(&scheduler);
}
