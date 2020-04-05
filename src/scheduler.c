#include <os-simulator/scheduler.h>

#include <stdint.h>

#include <os-simulator/cpu.h>
#include <os-simulator/cpu_t.h>
#include <os-simulator/pcb.h>
#include <os-simulator/memory.h>
#include <os-simulator/driver.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Max # of jobs loaded into RAM
 */
#define SCHEDULER_MAX_JOBS	8

/*
	Process control card (pcc)
 */

struct pcc {
	int16_t id, instr_count, priority, input_buff_size,
	output_buff_size, temp_buff_size;
};

struct scheduler {
	struct pcb running;
	struct pcb ready[SCHEDULER_MAX_JOBS - 1];
	int16_t ready_size, job_index, total_jobs;

	int32_t input_buff[PCB_INPUT_BUFF_SIZE], 
		output_buff[PCB_OUTPUT_BUFF_SIZE], temp_buff[PCB_TEMP_BUFF_SIZE];
};

static struct scheduler* _scheduler;

void
_scheduler_load_program(void)
{
	int32_t* disk;
	struct pcc* pcc;
	struct pcb* pcb;

	disk = disk_get_buff();

	pcc = (struct pcc*)&disk[disk[_scheduler->job_index]];
	_scheduler->job_index++;
	
	pcb = &_scheduler->ready[0];
	_scheduler->ready_size++;

	pcb->job_id = pcc->id;
	pcb->size = pcc->instr_count + pcc->input_buff_size;
	pcb->priority = pcc->priority;
	pcb->status = PCB_STATUS_NEW;
	_scheduler->ready_size++;
}

void
_scheduler_schedule_program(void)
{
	_scheduler->running = _scheduler->ready[SCHEDULER_MAX_JOBS - 1];
	memmove(_scheduler->ready + 1, _scheduler->ready, --_scheduler->ready_size);

	int32_t* ram = ram_get_buff();
	int32_t* pcb = (int32_t*)&_scheduler->running;

	dispatcher_dispatch_job(pcb - ram);
}

void
_scheduler_pcb_load_next(void)
{
	int32_t* disk;
	struct pcc* pcc;
	struct pcb* pcb;

	uint16_t start;

	disk = disk_get_buff();

	if (_scheduler->job_index + 1 > disk[0]) {
//		driver_signal_exit();
		dispatcher_dispatch_job(0);
	}
}

void
scheduler_init(void)
{
	_scheduler = (struct scheduler*)ram_get_buff();
}

void
scheduler_cycle(void)
{
	int32_t* ram;
	uint16_t addr;
	struct pcb* pcb;

	addr = cpu_pcb_get();
	if (addr == 0) {
	}

	ram = ram_get_buff();
	pcb = (struct pcb*)&ram[addr];
	if (pcb->status == PCB_STATUS_TERMINATED) {
	}
}

uint16_t
scheduler_pcb_get_next(void)
{
	return 0;
}

uint16_t
scheduler_pcb_get_current(void)
{
	return 0;
}
