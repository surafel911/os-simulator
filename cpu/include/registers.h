#ifndef _REGISTRY_H_
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
