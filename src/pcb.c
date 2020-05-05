#include <os-simulator/pcb.h>

#include <stdint.h>
#include <stdbool.h>

#include <os-simulator/register.h>

void
pcb_init(struct pcb* pcb)
{
	pcb->base_addr = 0;

	pcb->jcc.id = 0;
	pcb->jcc.size = 0;
	pcb->jcc.priority = 0;

	pcb->cpu_state.program_counter = 0;
	pcb->cpu_state.input_buffer_addr = 0;
	pcb->cpu_state.temp_buffer_addr = 0;
	pcb->cpu_state.output_buffer_addr = 0;

	registers_init(pcb->cpu_state.registers);
}
