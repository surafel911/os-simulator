#include "registers.h"
#include "instructions.h"

void rd(int32_t input_b)
{
    set_reg(reg_acc, input_b);
}

void wr(int32_t output_b)
{
    output_b = get_reg(reg_acc);
}

void st(int32_t reg, int32_t ram)
{
    ram = get_reg(reg);
}

void lw(int32_t ram, int32_t reg)
{
    set_reg(get_reg(reg), ram);
}

void mov(int32_t reg_s, int32_t reg_d)
{
    set_reg(reg_d, get_reg(reg_s));
}

void add(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    set_reg(reg_d, get_reg(reg_f_s) + get_reg(reg_s_s));
}

void sub(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    set_reg(reg_d, reg_f_s - reg_s_s);
}

void mul(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    set_reg(reg_d, reg_f_s * reg_s_s);
}

void div(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    set_reg(reg_d, reg_f_s / reg_s_s);
}

void and(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    reg_d = reg_f_s & reg_s_s;
}

void or(int32_t reg_f_s, int32_t reg_s_s, int32_t reg_d)
{
    reg_d = reg_f_s | reg_s_s;
}

void movi(int32_t ram, int32_t reg, char option)
{
    if (option == 'a')
        reg = &ram;
    else
        reg = ram;
}

void addi(int32_t data, int32_t reg)
{
    if (option == 'a')
        reg = &ram;
    else
        reg = ram;
}

void muli(int32_t data, int32_t reg)
{
    
}

void divi(int32_t data, int32_t reg)
{

}

void ldi(int32_t data, int32_t reg, char option)
{

}

void slt(int32_t reg_s, int32_t reg_b, int32_t reg_d)
{

}

void slti(int32_t reg_s, int32_t data, int32_t reg_d)
{

}

bool hlt()
{

}

void nop()
{

}

void jmp(int32_t reg_d)
{

}

void cmp(int32_t reg_f_s, int32_t reg_s_s)
{

}

void ls(int32_t reg)
{

}

void rs(int32_t reg)
{

}

void BEQ(int32_t reg_b, int32_t reg_d)
{

}

void BNE(int32_t reg_b, int32_t reg_d)
{

}

void BEZ(int32_t reg_b)
{

}

void BNZ(int32_t reg_b)
{

}

void BGZ(int32_t reg_b)
{

}

void BLZ(int32_t reg_b)
{

}