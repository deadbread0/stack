#include <stdio.h>
#include <math.h>
#include "include\operations_with_stack.h"

void StackPush(spu_t* spu, int num)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    // int *data = stk->data;
    int capacity = stk->capacity;

    if (size >= capacity - 2)
    {
        int *new_ptr = (int *)realloc(stk->data, (capacity * 2 + 1) * sizeof(int));
        stk->data = new_ptr;
        StackVerify(stk);
        stk->capacity = capacity * 2;
        stk->data[stk->capacity] = RIGHT_CONSTANT;
    }
    // printf("\nsize before++: %d\n", stk->size);
    stk->size++;
    // printf("data:%d size+1:%d\n", num, size+1);
    stk->data[size + 1] = num;
    // stk->size++;
    // if (stk->size != 1)
    // {
    //     stk->size++;
    // }
}

void Pushr(spu_t* spu, int reg)
{
    stack_t* stk = spu->stack;
    spu->regs[reg] = stk->data[stk->size];
    stk->size--;
}

void Pushm(spu_t* spu, int num_of_name)//from stk to ram
{
    stack_t* stk = spu->stack;
    spu->ram[num_of_name] = stk->data[stk->size];//крч сначала закидываем имя в стек, и только потом в оп
    // printf("*ram:%d stk:%d stksize:%d num_of_name:%d*", spu->ram[num_of_name], stk->data[stk->size], stk->size, num_of_name);
    // spu->nametable[num_of_name] = 
    stk->data[stk->size] = 0;
    spu->stack->size--;
}

void StackPop(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    // int capacity = stk->capacity;

    printf("last number from stack: %d\n", data[size]);
    stk->data[size] = 0;
    stk->size--;
}

void TssStackPop(spu_t* spu, int n)
{
    stack_t* stk = spu->stack;
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    // printf("??\n");
    // int capacity = stk->capacity;

    // printf("last number from stack: %d\n", data[size]);
    stk->data[size] = 0;
    stk->size--;
}

void Popr(spu_t* spu, int reg)
{
    spu->regs[reg] = 0;
}

void Popm(spu_t* spu, int num_of_name)//add num in stack
{
    stack_t* stk = spu->stack;
    // if (stk->size == 0)
    // {
    // stk->size++;
    // }
    // printf("\npushm{\nstksize:%d num_of_name:%d\n", stk->size, num_of_name);
    spu->stack->data[stk->size + 1] = spu->ram[num_of_name];
    // printf("^%d %d^}\n", spu->stack->data[stk->size + 1], spu->ram[num_of_name]);
    stk->size++;

    // spu->ram[num_of_name] = 0;
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
    free(spu->ram);
    free(spu->nametable);
    // stk->data = NULL;
}
