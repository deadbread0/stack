#include <stdio.h>
#include <stdlib.h>
#include "init.h"

void StackInit(stack_t *stk, const int CAPACITY)
{
    StackVerify(stk);
    stk->capacity = CAPACITY;
    int *data = (int *)calloc(CAPACITY + 1, sizeof(int));

    stk->data = data;
    stk->data[0] = 0xFEDCBA;
    stk->data[CAPACITY] = 0xFEDCBA;
    stk->size = 0;
    stk->error = NO_ERRORS;
}

spu_t SpuInit(stack_t *stk)
{
    spu_t spu = {};
    spu.stack = stk;
    spu.ip = 0;
    int regs[SIZE_OF_REG] = {0};
    spu.regs = regs;
    int steps[MAX_SIZE_OF_CODE] = {0};
    spu.steps = steps;
    spu.amount_of_steps = 0;
    int code[MAX_SIZE_OF_CODE] = {0};/////
    spu.code = code;
    return spu;
}

void FillSpu(spu_t* spu, char* inf)
{
    int ip = spu->ip;
    spu->code[ip + spu->amount_of_steps] = atoi(inf);
    int numm = 0;
    int amount_of_prm = LooksForNumInStringForAsm(inf, &numm);
    if (amount_of_prm == 1)
    {
        spu->amount_of_steps++;
        spu->code[ip + spu->amount_of_steps] = numm;
        spu->steps[ip] = 2;
        spu->ip++;
    }
    else
    {
        spu->steps[ip] = 1;
        spu->ip++;
    }

}
