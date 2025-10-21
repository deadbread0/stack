/*это основная программа, ввод из файла: команды - числа, ввод из терминала - команды буквами*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "main.h"


int main(const int argc, const char* argv[])
{
    stack_t stk = {};
    StackInit(&stk, CAPACITY);
    spu_t spu = SpuInit(&stk);

    const char* filee_name = argc > 0? argv[1]: "";
    if (filee_name != nullptr)
    {
        ProgramForFileInput(&spu, filee_name);
        /*for (int i = 0; i < SIZE_OF_REG; i++)
            printf("%d\n", regs[i]);*/
        return 0;
    }
    ProgramForTerminalInput(&spu);
    /*for (int i = 0; i < SIZE_OF_REG; i++)
        printf("%d\n", regs[i]);*/
    return 0;
}







