#include <stdio.h>
#include <string.h>
#include "include\compare_and_run_functions.h"

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
                // printf("%s\n", ArrayOfCommands[i].command);
                return i;
            }
    }
    return -1;
}

void FindJumpsAndFillLabels(spu_t* spu)//////
{
    int numm = 0;
    stack_t* stack = spu->stack;
    int c = -2;//2 это типа длина первой команды
    int amount_of_func = 0;
    for (int i = 0; i < MAX_SIZE_OF_CODE; i++)
    {
        // int num_of_func = spu->code[spu->steps[i] + c];
        // printf("|%d|", num_of_func);
        if (spu->steps[i] == 0)
        {
            amount_of_func = i;
            break;
        }
        // c += spu->steps[i];
    }

    for (int i = 0; i < amount_of_func; i++)
    {
        int num_of_func = spu->code[spu->steps[i] + c];
        // printf("|%d|", num_of_func);//вдруг это будет важно, тут функция перед hlt неправильно выводится
        if (num_of_func == 10)
        {
            spu->labels[spu->code[spu->steps[i] + c + 1]] = spu->steps[i] + c;
        }
        c += spu->steps[i];
    }
}

bool RunFuncForMC(spu_t* spu)
{
    int numm = 0;
    stack_t* stack = spu->stack;
    int ip = spu->ip;
    int num_of_func = spu->code[ip + spu->amount_of_steps];
    // printf("%d ", ip + spu->amount_of_steps);
    // printf("%d - %d %d\n", num_of_func, spu->ip, spu->stack->size);

        if ((num_of_func == 0 || num_of_func >= 10) && num_of_func < 17)
        {
            numm = spu->code[ip + spu->amount_of_steps + 1];
            // printf("%d - %d\n", num_of_func, numm);
            // printf("before ");
            StackVerify(stack, numm);
            // printf("after ");
            ArrayOfCommands[num_of_func].pt(spu, numm);
            return true;
        }
        else if ((num_of_func > 0 && num_of_func != num_of_hlt && num_of_func < first_reg_command) || num_of_func == 19)
        {
            // if (num == 19)
            // {printf("blblblbl_of_func\n");}
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

        else if (num_of_func == 17 || num_of_func == 18)//
        {
            int num_of_name = spu->code[ip + spu->amount_of_steps + 1];
            // printf("%d\n", num_of_name);
            if (num_of_name >= 0)
            {
                // printf("%s\n", ArrayOfCommands[num_of_func].command);
                ArrayOfCommands[num_of_func].pt(spu, num_of_name);
                // printf("qq");
                return true;
            }
        }

        // printf("%d - %d\n", num_of_func, numm);
        if (num_of_func != num_of_hlt)
        {
            numm = 1;
            // printf("**");
            StackVerify(stack, numm);
            return false;
        }
        // printf("%d - %d\n", num_of_func, numm);
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