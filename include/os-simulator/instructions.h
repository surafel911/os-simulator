#ifndef OS_SIMULATOR_INSTRUCTIONS_H
#define OS_SIMULATOR_INSTRUCTIONS_H

#include <stdint.h>

#include <os-simulator/pcb.h>

#define INSTRUCTION_OPCODE_MASK			((1 << 5) - 1)
#define INSTRUCTION_OPCODE_OFFSET		24

typedef void (*instruction_fn)(struct pcb*, uint32_t);

void
instruction_rd(struct pcb* pcb, uint32_t instruction);

void
instruction_wr(struct pcb* pcb, uint32_t instruction);

void
instruction_st(struct pcb* pcb, uint32_t instruction);

void
instruction_lw(struct pcb* pcb, uint32_t instruction);

void
instruction_mov(struct pcb* pcb, uint32_t instruction);

void
instruction_add(struct pcb* pcb, uint32_t instruction);

void
instruction_sub(struct pcb* pcb, uint32_t instruction);

void
instruction_mul(struct pcb* pcb, uint32_t instruction);

void
instruction_div(struct pcb* pcb, uint32_t instruction);

void
instruction_and(struct pcb* pcb, uint32_t instruction);

void
instruction_or(struct pcb* pcb, uint32_t instruction);

void
instruction_movi(struct pcb* pcb, uint32_t instruction);

void
instruction_addi(struct pcb* pcb, uint32_t instruction);

void
instruction_muli(struct pcb* pcb, uint32_t instruction);

void
instruction_divi(struct pcb* pcb, uint32_t instruction);

void
instruction_ldi(struct pcb* pcb, uint32_t instruction);

void
instruction_slt(struct pcb* pcb, uint32_t instruction);

void
instruction_slti(struct pcb* pcb, uint32_t instruction);

void
instruction_hlt(struct pcb* pcb, uint32_t instruction);

void
instruction_nop(struct pcb* pcb, uint32_t instruction);

void
instruction_nop(struct pcb* pcb, uint32_t instruction);

void
instruction_jmp(struct pcb* pcb, uint32_t instruction);

void
instruction_beq(struct pcb* pcb, uint32_t instruction);

void
instruction_bne(struct pcb* pcb, uint32_t instruction);

void
instruction_bez(struct pcb* pcb, uint32_t instruction);

void
instruction_bnz(struct pcb* pcb, uint32_t instruction);

void
instruction_bgz(struct pcb* pcb, uint32_t instruction);

void
instruction_blz(struct pcb* pcb, uint32_t instruction);

#endif // OS_SIMULATOR_INSTRUCTIONS_H
