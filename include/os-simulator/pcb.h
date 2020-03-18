#ifndef OS_SIMULATOR_PCB_H
#define OS_SIMULATOR_PCB_H

/* PCB is synonymous with process/program */

#include <os-simulator/cpu_t.h>

/*
 # of words for the input buffer
 */
#define PCB_INPUT_BUFF_SIZE		0x14

/*
 # of words for the output buffer
 */
#define PCB_OUTPUT_BUFF_SIZE	0xC

/*
 # of words for the temp buffer
 */
#define PCB_TEMP_BUFF_SIZE		0xC

enum pcb_status {
	PCB_STATUS_NEW,
	PCB_STATUS_READY,
	PCB_STATUS_RUNNING,
	PCB_STATUS_WAITING,
	PCB_STATUS_TERMINATED,
};

struct buffer {
	uint16_t addr, size;
};

struct pcb {
	uint16_t job_id, size, priority, base_register;

	enum pcb_status status;
	struct cpu_state cpu_state;
	struct buffer input_buff, output_buff, temp_buff;
};

void
pcb_init(struct pcb* pcb);

#endif // OS_SIMULATOR_PCB_H
