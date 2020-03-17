#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

#include <stdint.h>
#include <stdbool.h>

// Read content of I/P buffer into a accumulator
void rd(int32_t* input_b);
// Writes the content of accumulator into O/P buffer
void wr(int32_t* output_b);
// Move content of a register into an address
void st(int32_t reg, int32_t* addr);
// Move the contents of an address into register
void lw(int32_t* reg, int32_t addr);
// Move content of a register into another register
void mov(int32_t reg_s, int32_t reg_d);
// Store the sum of two registers in a register
void add(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store the difference of two registers in a register
void sub(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store the product of two registers in a register
void mul(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store the quotient of two registers in a register
void div(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store the AND of two registers in a register
void and(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store the OR of two registers in a register
void or(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d);
// Store an address into a register
void movi(int32_t address, int32_t reg, char option);
// Add the data value of a resgister into another register 
void addi(int32_t data, int32_t reg);
// Multply the data value of a register into another resgister
void muli(int32_t data, int32_t reg);
// Divide the data value of a register into another register
void divi(int32_t data, int32_t reg);
// Load the data value of a register into another resgister
void ldi(int32_t ram, int32_t reg);
// 
void slt(int32_t reg_s, int32_t reg_b, int32_t reg_d);
void slti(int32_t reg_s, int32_t data, int32_t reg_d);
bool hlt();
void nop();
void jmp(int32_t reg_d);
void cmp(int32_t reg_f_s, int32_t reg_s_s);
void ls(int32_t reg);
void rs(int32_t reg);
void BEQ(int32_t reg_b, int32_t reg_d);
void BNE(int32_t reg_b, int32_t reg_d);
void BEZ(int32_t reg_b);
void BNZ(int32_t reg_b);
void BGZ(int32_t reg_b);
void BLZ(int32_t reg_b);

#endif /* instructions.h */#ifndef _REGISTRY_H_
#define _REGISTRY_H_

#include <stdint.h>

/*
Associating a number with each register
*/
#define reg_acc   	0x0000
#define reg_zero    0x0001
#define reg_g1  	0x0002
#define reg_g2  	0x0003
#define reg_g3  	0x0004
#define reg_g4  	0x0005
#define reg_g5  	0x0006
#define reg_g6  	0x0007
#define reg_g7  	0x0008
#define reg_g8  	0x0009
#define reg_g4  	0x0010
#define reg_g5  	0x0011
#define reg_g6  	0x0012
#define reg_g7  	0x0013
#define reg_g8  	0x0014
#define reg_g9  	0x0015

static struct registers
{
    int32_t acc;
    int32_t zero;
    int32_t g1;
    int32_t g2;
    int32_t g3;
    int32_t g4;
    int32_t g5;    
    int32_t g6;
    int32_t g7;
    int32_t g8;
    int32_t g9;
};

int32_t get_reg(int32_t symbol);
void set_reg(int32_t symbol, int32_t data);

#endif /* registry.h */
