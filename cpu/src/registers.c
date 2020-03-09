#include <stdint.h>

#include "registers.h"

int32_t get_reg(int32_t symbol)
{
    struct registers reg;

    switch (symbol)
    {
    case reg_acc: return reg.acc;
    case reg_zero: return reg.zero;
    case reg_g1: return reg.g1;
    case reg_g2: return reg.g2;
    case reg_g3: return reg.g3;
    case reg_g4: return reg.g4;
    case reg_g5: return reg.g5;
    case reg_g6: return reg.g6;
    case reg_g7: return reg.g7;
    case reg_g8: return reg.g8;
    default: return reg.g9;
    }
}

void set_reg(int32_t symbol, int32_t data)
{
    struct registers reg;
    
    switch (symbol)
    {
    case reg_acc: reg.acc = data;
    case reg_g1: reg.g1 = data;
    case reg_g2: reg.g2 = data;
    case reg_g3: reg.g3 = data;
    case reg_g4: reg.g4 = data;
    case reg_g5: reg.g5 = data;
    case reg_g6: reg.g6 = data;
    case reg_g7: reg.g7 = data;
    case reg_g8: reg.g8 = data;
    default: reg.g9 = data;
    }
}