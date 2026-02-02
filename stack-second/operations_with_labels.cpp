#include <stdio.h>
#include <assert.h>
#include "include\operations_with_labels.h"

void FillLabels(spu_t* spu, int num)
{
    StackVerify(spu->stack, num);
    spu->labels[num] = spu->ip + spu->amount_of_steps;
    // printf("%d ", spu->ip + spu->amount_of_steps);
}

void FillSpuForJump(spu_t* spu, int num)
{
    spu->amount_of_steps = 0;
        int i = 0;
        while (spu->amount_of_steps < num)
        {
            spu->amount_of_steps += spu->steps[i];
            i++;
        }
        spu->amount_of_steps -= i;
        spu->ip = i;
}

void JumpIfBelow(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    // printf("\n%d - %d\n", stk->data[ip], stk->data[ip - 1]);
    if (stk->data[stk->size] < stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}

void JumpIfBelowOrEqual(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    if (stk->data[stk->size] <= stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}

void JumpIfAbove(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    if (stk->data[stk->size] > stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}

void JumpIfAboveOrEqual(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    if (stk->data[stk->size] >= stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}

void JumpIfEqual(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    // printf("z%d %d\n", stk->data[stk->size], stk->data[stk->size - 1]);
    if (stk->data[stk->size] == stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}

void JumpIfNotEqual(spu_t* spu, int num)
{
    stack_t *stk = spu->stack;
    int ip = spu->ip;

    if (stk->data[stk->size] != stk->data[stk->size - 1])
        FillSpuForJump(spu, num);
}