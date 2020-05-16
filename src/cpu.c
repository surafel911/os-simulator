#include <os-simulator/cpu.h>

#include <stdint.h>

#include <os-simulator/cpu_t.h>
#include <os-simulator/storage.h>
#include <os-simulator/register.h>
#include <os-simulator/instructions.h>

static struct pcb _pcb;

static instruction_fn _instruction_fn_table[] = {
	&instruction_rd,
	&instruction_wr,
	&instruction_st,
	&instruction_lw,
	&instruction_mov,
	&instruction_add,
	&instruction_sub,
	&instruction_mul,
	&instruction_div,
	&instruction_and,
	&instruction_or,
	&instruction_movi,
	&instruction_addi,
	&instruction_muli,
	&instruction_divi,
	&instruction_ldi,
	&instruction_slt,
	&instruction_slti,
	&instruction_hlt,
	&instruction_nop,
	&instruction_jmp,
	&instruction_beq,
	&instruction_bne,
	&instruction_bez,
	&instruction_bnz,
	&instruction_bgz,
	&instruction_blz,
};

static inline uint32_t
_cpu_instruction_fetch(struct cpu_state* cpu_state)
{
	return storage_ram_get(cpu_state->program_counter++);
}

static inline uint8_t
_cpu_instruction_decode(uint32_t instruction)
{
	return ((instruction >> INSTRUCTION_OPCODE_OFFSET) &
		INSTRUCTION_OPCODE_MASK);
}

#include <stdio.h>

void
cpu_execute(void)
{
	uint8_t opcode;
	uint32_t instruction;

	do {
		instruction = _cpu_instruction_fetch(&_pcb.cpu_state);
		opcode = _cpu_instruction_decode(instruction);

		_instruction_fn_table[opcode](&_pcb, instruction);
	} while (_pcb.jcc.priority != 0);

	printf("completed job %d\n", _pcb.jcc.id);
}

struct pcb 
cpu_pcb_get(void)
{
	return _pcb;
}

void
cpu_pcb_set(struct pcb pcb)
{
	_pcb = pcb;
}
