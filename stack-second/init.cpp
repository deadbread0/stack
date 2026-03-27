#include <stdio.h>
#include <stdlib.h>
#include "include\init.h"

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

void SpuInit(stack_t *stk, spu_t *spu)
{
    spu->stack = stk;
    spu->ip = 0;
    int steps[MAX_SIZE_OF_CODE] = {0};
    spu->steps = steps;
    spu->amount_of_steps = 0;
    int code[MAX_SIZE_OF_CODE] = {0};/////
    spu->code = code;
    int labels[AMOUNT_OF_LABELS] = {0};
    spu->labels = labels;
    int regs[SIZE_OF_REG] = {0};
    spu->regs = regs;
    int* ram = (int*)calloc(SIZE_OF_RAM, sizeof(int));
    spu->ram = ram;
    names_t* nametable = (names_t*)calloc(MAX_AMOUNT_OF_VAR, sizeof(names_t));
    spu->nametable = nametable;
}

void FillSpu(spu_t* spu, char* inf)
{
    int ip = spu->ip;
    spu->code[ip + spu->amount_of_steps] = atoi(inf);
    int numm = 0;
    bool prm_there = LooksForNumInString(inf, &numm);
    if (prm_there == true)
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
