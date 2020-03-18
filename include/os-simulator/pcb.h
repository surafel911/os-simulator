#ifndef OS_SIMULATOR_PCB_H
#define OS_SIMULATOR_PDB_H

/* PCB is synonymous with process/program */

enum pcb_status {
	PCB_STATUS_NEW,
	PCB_STATUS_RUNNING,
	PCB_STATUS_WAITING,
	PCB_STATUS_READY,
	PCB_STATUS_TERMINATED,
};

struct pcb_buffers {
	int32_t* input;
	int32_t* output;
	int32_t* temp;
	int32_t input_size, output_size, temp_size;
};

struct pcb {
	int32_t cpi_id, code_size, priority;

	int32_t* base_register;

	struct cpu_state cpu_state;
	enum program_status status;
	struct pcb_buffers buffers;
};

#endif // OS_SIMULATOR_PDB_H
