#include <stdio.h>
#include <math.h>
#include "include\arithmetic_operations.h"

void FunctionForKillingCopyPaste(spu_t* spu, int* last, int* practically_last)
{
    stack_t* stk = spu->stack;
    int *data = stk->data;
    int size = stk->size;

    *last = data[size];
    *practically_last = data[size - 1];
    stk->size--;
}

void AddNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = 0, practically_last = 0;
    FunctionForKillingCopyPaste(spu, &last, &practically_last);
    stk->data[stk->size] = last + practically_last;
}

void DifferenceOfNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = 0, practically_last = 0;
    FunctionForKillingCopyPaste(spu, &last, &practically_last);
    stk->data[stk->size] = practically_last - last;
}

void QuotientOfNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = 0, practically_last = 0;
    FunctionForKillingCopyPaste(spu, &last, &practically_last);
    stk->data[stk->size] = practically_last / last;
}

void MultiplyingNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = 0, practically_last = 0;
    FunctionForKillingCopyPaste(spu, &last, &practically_last);
    stk->data[stk->size] = last * practically_last;
}

void SquareRootOfNumber(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    stk->data[stk->size] = sqrt(stk->data[stk->size]);
}
