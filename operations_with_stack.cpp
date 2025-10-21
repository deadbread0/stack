#include <stdio.h>
#include <math.h>
#include "operations_with_stack.h"

void AddNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;
    int *data = stk->data;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = data[size];
    int practically_last = data[size - 1];
    stk->size--;
    stk->data[stk->size] = last + practically_last;
}

void DifferenceOfNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;
    int *data = stk->data;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = data[size];
    int practically_last = data[size - 1];
    stk->size--;
    stk->data[stk->size] = practically_last - last;
}

void QuotientOfNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;
    int *data = stk->data;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = data[size];
    int practically_last = data[size - 1];
    stk->size--;
    stk->data[stk->size] = practically_last / last;
}

void MultiplyingNumbers(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    int size = stk->size;
    int *data = stk->data;

    if (size - 1 <= 0)
    {
        stk->size = size - 2;
        StackVerify(stk);
        return;
    }

    int last = data[size];
    int practically_last = data[size - 1];
    stk->size--;
    stk->data[stk->size] = last * practically_last;
}

void SquareRootOfNumber(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    stk->data[stk->size] = sqrt(stk->data[stk->size]);
}

void StackPush(spu_t* spu, int num)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    int capacity = stk->capacity;

    if (size >= capacity - 2)
    {
        int *new_ptr = (int *)realloc(stk->data, (capacity * 2 + 1) * sizeof(int));
        stk->data = new_ptr;
        StackVerify(stk);
        stk->capacity = capacity * 2;
        stk->data[stk->capacity] = RIGHT_CONSTANT;
    }
    stk->size++;
    stk->data[size + 1] = num;
}

void Popr(spu_t* spu, int reg)
{
    stack_t* stk = spu->stack;
    spu->regs[reg] = stk->data[stk->size];
    stk->size--;
}

void StackPop(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    int capacity = stk->capacity;

    printf("last number from stack: %d\n", data[size]);
    stk->data[size] = 0;
    stk->size--;
}

void Pushr(spu_t* spu, int reg)
{
    spu->regs[reg] = 0;
}

void StackDump(spu_t* spu) 
{
    stack_err_t ArrayOfErrors[] = {{NO_ERRORS, "no errors"},
                               {MEMORY_ALLOCATION, "memory allocation error"},
                               {NULLPTR, "null pointer detected"},
                               {CAPACITY_LESS_THAN_SIZE, "capacity less than size"},
                               {CAPACITY_OR_SIZE_LESS_THAN_ZERO, "capacity or size less than zero (not enough numbers in stack)"},
                               {NO_PARAMETER, "parameter was not entered"},
                               {ATTACK_FROM_THE_LEFT, "problems with stack"},
                               {ATTACK_FROM_THE_RIGHT, "problems with stack"},
                               {ERROR_COMAND, "you entered a non-existent command"}};
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    int capacity = stk->capacity;

    FILE* result;
    result = fopen("result", "w");
    fprintf(result, "%s called from %s: %d\n"
           "Stack [%p]\n"
           "{\n size = %d\n"
           " capacity = %d\n"
           " errors: %s\n"
           " data [%p]\n {\n", __func__,  __FILE__, __LINE__, stk, size, capacity - 1, ArrayOfErrors[stk->error].description, data);
    for (int i = 0; i < size; i++)
        fprintf(result, "  *[%d] = %d\n", i, data[i + 1]);
    for (int i = size; i < capacity - 1; i++)
        fprintf(result, "   [%d] = %d (garbage)\n", i, data[i + 1]);
    fprintf(result, " }\n}\n");
}

void StackDestroy(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);
    
    free(stk->data);
    stk->data = NULL;
}