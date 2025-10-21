#include <stdio.h>
#include "input_and_output.h"


bool Input(spu_t* spu)
{
    StackVerify(spu->stack);
    printf("enter the command and the value if necessary\n");
    char inf[MAX_LEN_OF_WORD] = {0};
    gets(inf);
    return RunFunc(spu, inf);
    
}

void InputFromFile(FILE* filee, spu_t* spu)
{
    StackVerify(spu->stack);
    char inf[MAX_LEN_OF_WORD] = {0};

    fgets(inf, MAX_LEN_OF_WORD, filee);
    while (*inf != 55 && *inf != EOF)///
    {
        FillSpu(spu, inf);
        fgets(inf, MAX_LEN_OF_WORD, filee);
    }
}

void OutputForUser(stack_t *stk)
{
    StackVerify(stk);
    StackErr_t err = stk->error;
    if (err != NO_ERRORS)
        printf("%s\n", ArrayOfErrors[err].description);
}