#include <os-simulator/instructions.h>

#include <stdint.h>

#define INSTRUCTION_REGISTER_MASK		((1 << 4) - 1)
#define INSTRUCTION_ADDRESS_MASK		((1 << 16) - 1)
#define INSTRUCTION_JUMPADDRESS_MASK	((1 << 24) - 1)

void
instruction_rd(struct pcb* pcb, uint32_t instruction)
{
	uint16_t address;
	uint8_t reg1, reg2;

	reg1 = ((instruction >> 20) & INSTRUCTION_REGISTER_MASK);
	reg2 = ((instruction >> 16) & INSTRUCTION_REGISTER_MASK);
	address = (instruction & ((1 << 16) - 1));


}

void
instruction_wr(struct pcb* pcb, uint32_t instruction)
{
	uint16_t address;
	uint8_t reg1, reg2;

	reg1 = ((instruction >> 20) & INSTRUCTION_REGISTER_MASK);
	reg2 = ((instruction >> 16) & INSTRUCTION_REGISTER_MASK);
	address = (instruction & ((1 << 16) - 1));
}

void
instruction_st(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_lw(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_mov(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_add(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_sub(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_mul(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_div(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_and(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_or(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_movi(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_addi(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_subi(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_muli(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_divi(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_ldi(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_slt(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_slti(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_hlt(struct pcb* pcb, uint32_t instruction)
{
	pcb->jcc.priority = 0;
}

void
instruction_nop(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_jmp(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_beq(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_bne(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_bez(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_bnz(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_bgz(struct pcb* pcb, uint32_t instruction)
{
}

void
instruction_blz(struct pcb* pcb, uint32_t instruction)
{
}
