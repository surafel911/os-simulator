#include <os-simulator/scheduler.h>

#include <stdint.h>

#include <os-simulator/cpu.h>
#include <os-simulator/cpu_t.h>
#include <os-simulator/pcb.h>
#include <os-simulator/memory.h>

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
	struct pcb pcbs[SCHEDULER_MAX_JOBS];
	int16_t new_size, ready_size, running_size, waiting_size, 
		pcb_count, job_index, total_jobs;

	int32_t input_buff[PCB_INPUT_BUFF_SIZE], 
		output_buff[PCB_OUTPUT_BUFF_SIZE], temp_buff[PCB_TEMP_BUFF_SIZE];
};

/*
 Max # of words reeserved for the scheduler at head of RAM
 */
#define SCHEDULER_SCHEDULER_RESERVE	(sizeof(struct scheduler) + \
	PCB_TOTAL_BUFF_SIZE)

#include <stdio.h>
#include <stdlib.h>

static struct scheduler* _scheduler;

void
_scheduler_pcb_load_next(void)
{
	int32_t* disk;
	struct pcc* pcc;
	struct pcb* pcb;

	uint16_t start;

	disk = disk_get_buff();

	if (_scheduler->job_index + 1 > disk[0]) {
		// TODO: Handle this case
	}

	if (_scheduler->new_size < SCHEDULER_MAX_JOBS) {
		start = disk[_scheduler->job_index + 1];
		pcc = (struct pcc*)&disk[start];
		
		pcb = &_scheduler->pcbs[_scheduler->pcb_count - 1];

		pcb->job_id = pcc->id;
		pcb->size = pcc->instr_count + pcc->input_buff_size;
		pcb->priority = pcc->priority;
		pcb->status = PCB_STATUS_NEW;
		_scheduler->pcb_count++;

		/*
		 TODO: DMA call to put JUST CODE in RAM and Data into
		 input buffer

 		 int addr = 256 + (32 * _scheduler->pcb_count);
		 */
	}
}

void
scheduler_init(void)
{
	struct scheduler* scheduler = (struct scheduler*)ram_get_buff();

}

void
scheduler_cycle(void)
{
#if 0
	int32_t* ram;
	uint16_t addr;
	struct pcb* pcb;

	addr = cpu_pcb_get();
	if (addr == 0) {
		_scheduler->pcb_load_next();
	}

	ram = ram_get_buff();
	pcb = (struct pcb*)&ram[addr];
	if (pcb->status == PCB_STATUS_TERMINATED) {
		/* TODO: add process to terminated queue and add 
		 new process to ready queue
		 */
	}
	
#else
	printf("%d\n", sizeof(*_scheduler) / 4);
#endif 
}

#define SCHEDULER_JOB_CHUNK_SIZE


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
