#include <stdio.h>
#include <string.h>
#include "compare_and_run_functions.h"

int CompareStringWithCommandForMC(int num)
{
    for (int i = 0; i < amount_of_commands; i++)
    {
        if (i == num)
            return i;
    }
    return -1;
}

int CompareStringWithCommand(char *string)
{
    RemoveSymbOfNewStr(string);
    int len = strlen(string);
    if (len > len_for_strncmp)
        len = len_for_strncmp;
    for (int i = 0; i < amount_of_commands; i++)
    {
        if (strncmp(string, ArrayOfCommands[i].command, len) == 0)//
            {
               // printf("%s\n", ArrayOfCommands[i].description);
                return i;
            }
    }
    return -1;
}

bool RunFuncForMC(spu_t* spu)
{
    int numm = 0, counter = 0;
    stack_t* stack = spu->stack;
    int ip = spu->ip;
    int num_of_func = spu->code[ip + spu->amount_of_steps];

        if (num_of_func == 0 || num_of_func >= 10)
        {
            numm = spu->code[ip + spu->amount_of_steps + 1];
            StackVerify(stack, numm);
            ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if (num_of_func > 0 && num_of_func != num_of_hlt && num_of_func < first_reg_command)
        {
            StackVerify(spu->stack);
            ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if (num_of_func >= first_reg_command && num_of_func < 10)//
        {
            int reg = spu->code[ip + spu->amount_of_steps + 1];
            if (reg >= 0)
            {
                ArrayOfCommands[num_of_func].pt(spu, reg);
                return true;
            }
        }
        else if (num_of_func != num_of_hlt)
        {
            numm = 1;
            StackVerify(stack, numm);
            return false;
        }
        return false;
}

bool RunFunc(spu_t* spu, char* inf)
{
    int numm = 0, counter = 0;
    int comp = strncmp(inf, ArrayOfCommands[num_of_hlt].command, MAX_LEN_OF_WORD);

    int num_of_func = CompareStringWithCommand(inf);
        if (num_of_func == 0)
        {
            counter = LooksForNumInString(inf, &numm);
            StackVerify(spu->stack, numm);
            if (counter > 0)
                ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if (num_of_func > 0 && comp != 0 && num_of_func < first_reg_command)
        {
            StackVerify(spu->stack);
            ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if (num_of_func >= first_reg_command && num_of_func < 10)//
        {
            int reg = LooksForReg(inf);
            if (reg >= 0)
            {
                ArrayOfCommands[num_of_func].pt(spu, reg);
                return true;
            }
        }
        else if (num_of_func == 10)//
        {
            counter = LooksForNumInString(inf, &numm);
            StackVerify(spu->stack, numm);
            if (counter > 0)
                ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if (comp != 0)
        {
            numm = 1;
            StackVerify(spu->stack, numm);
            return false;
        }
        return false;
}