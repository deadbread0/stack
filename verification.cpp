#include <stdio.h>
#include "verification.h"

WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name)//
{
    *filee = fopen(filee_name, "rb");
    if (*filee == nullptr)
    {
        printf("File %s didn't open((\n", filee_name);
        return NO;
    }
    return YES;
}

void Canary(stack_t *stk)
{
    if (stk->data[0] != LEFT_CONSTANT)
        stk->error = ATTACK_FROM_THE_LEFT;
    else if (stk->data[stk->capacity] != RIGHT_CONSTANT)
        stk->error = ATTACK_FROM_THE_LEFT;
}

bool StackVerify(stack_t *stk, int prm)
{
    int size = stk->size;
    int *data = stk->data;
    int capacity = stk->capacity;

    if (stk == nullptr)
        stk->error = NULLPTR;
    else if (data == nullptr)
        stk->error = MEMORY_ALLOCATION;
    else if (size < 0 || capacity < 0)
        stk->error = CAPACITY_OR_SIZE_LESS_THAN_ZERO;
    else if (size > capacity)
        stk->error = CAPACITY_LESS_THAN_SIZE;
    else if (prm == 0)
        stk->error = NO_PARAMETER;
    else if (prm == 1)
        stk->error = ERROR_COMAND;
    if (stk->error == NO_ERRORS)
        return true;
    return false;
    
}
