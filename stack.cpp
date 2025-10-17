/*это основная программа, ввод из файла: команды - числа, ввод из терминала - команды буквами*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"


int main(const int argc, const char* argv[])
{
    stack_t stk = {};
    StackInit(&stk, CAPACITY);
    spu_t spu = SpuInit(&stk);

    const char* filee_name = argc > 0? argv[1]: "";
    if (filee_name != nullptr)
    {
        ProgrammForFileInput(&spu, filee_name);
        /*for (int i = 0; i < SIZE_OF_REG; i++)
            printf("%d\n", regs[i]);*/
        return 0;
    }
    ProgrammForTerminalInput(&stk);
    /*for (int i = 0; i < SIZE_OF_REG; i++)
        printf("%d\n", regs[i]);*/
    return 0;
}

void ProgrammForTerminalInput(stack_t *stk)
{
    bool prm_for_while = true, prm_for_while1 = true;
    while (prm_for_while && prm_for_while1)
    {
        prm_for_while = Input(stk);
        Canary(stk);
        prm_for_while1 = StackVerify(stk);
    }

    OutputForUser(stk);
    StackDump(stk);
    StackDestroy(stk);
}

void ProgrammForFileInput(spu_t* spu, const char* filee_name)
{
    bool prm_for_while = true, prm_for_while1 = true;
    FILE* filee = nullptr;
    if (!OpenAndCheckFileForReading(&filee, filee_name))
        return;
    while (prm_for_while && prm_for_while1)
    {
        prm_for_while = InputFromFile(filee, spu);
        Canary(spu->stack);
        prm_for_while1 = StackVerify(spu->stack);
    }

    OutputForUser(spu->stack);
    StackDump(spu->stack);
    StackDestroy(spu->stack);
}

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

bool Input(stack_t *stk)
{
    StackVerify(stk);
    printf("enter the command and the value if necessary\n");
    char inf[MAX_LEN_OF_WORD] = {0};
    gets(inf);
    return RunFunc(stk, inf);
    
}

bool InputFromFile(FILE* filee, spu_t* spu)
{
    StackVerify(spu->stack);
    char inf[MAX_LEN_OF_WORD] = {0};
    fgets(inf, MAX_LEN_OF_WORD, filee);
    if (*inf == '\0' || *inf == EOF)
        return false;
    return RunFuncForAsm(spu->stack, inf);
    
}

bool RunFuncForAsm(stack_t *stk, char* inf)
{
    int numm = 0, counter = 0;

    int num_of_func = CompareStringWithCommandForAsm(inf);
        if (num_of_func == 0)
        {
            counter = LooksForNumInStringForAsm(inf, &numm);
            StackVerify(stk, numm);
            if (counter > 0)
                ArrayOfCommands[num_of_func].pt(stk, numm);
            return true;
        }
        else if (num_of_func > 0 && atoi(inf) != num_of_hlt)
        {
            StackVerify(stk);
            ArrayOfCommands[num_of_func].pt(stk, numm);
            return true;
        }
        else if (atoi(inf) != num_of_hlt)
        {
            numm = 1;
            StackVerify(stk, numm);
            return false;
        }
        return false;
}

bool RunFunc(stack_t *stk, char* inf)
{
    int numm = 0, counter = 0;
    int comp = strncmp(inf, "hlt", MAX_LEN_OF_WORD);///

    int num_of_func = CompareStringWithCommand(inf);
        if (num_of_func == 0)
        {
            counter = LooksForNumInString(inf, &numm);
            StackVerify(stk, numm);
            if (counter > 0)
                ArrayOfCommands[num_of_func].pt(stk, numm);
            return true;
        }
        else if (num_of_func > 0 && comp != 0 && num_of_func < first_reg_command)
        {
            StackVerify(stk);
            ArrayOfCommands[num_of_func].pt(stk, numm);
            return true;
        }
        else if (num_of_func >= first_reg_command)//
        {
            int reg = LooksForReg(inf);
            if (reg >= 0)
            {
                ArrayOfCommands[num_of_func].pt(stk, reg);
                return true;
            }
        }
        else if (comp != 0)
        {
            numm = 1;
            StackVerify(stk, numm);
            return false;
        }
        return false;
}

int LooksForReg(char* str)
{
    int len = strlen(str) - 2;/////
    int num = (int)str[len] - (int)'a';
    if (num >= 0 && num < SIZE_OF_REG)
    {
        return num;
    }
    return -1;
}

int LooksForNumInStringForAsm(char* str, int* numm)
{
    int i = 1;//
    int num = 0, counter = 0;
    int num_of_command = atoi(str);
    while (num_of_command > 0)
    {
        i++;
        num_of_command = num_of_command / 10;
    }

    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
        {
            num = num * 10 + (int)str[i] - '0';
            counter++;
            i++;
            continue;
        }
        else if (counter != 0 && !isdigit(str[i]))
            break;
        i++;
    }
    if (counter != 0)
    {
        *numm = num;
        return 1;
    }
    return 0;
}

int LooksForNumInString(char* str, int* numm)
{
    int i = 0;//
    int num = 0, counter = 0;
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
        {
            num = num * 10 + (int)str[i] - '0';
            counter++;
            i++;
            continue;
        }
        else if (counter != 0 && !isdigit(str[i]))
            break;
        i++;
    }
    if (counter != 0)
    {
        *numm = num;
        return 1;
    }
    return 0;
}

int CompareStringWithCommandForAsm(char *string)
{
    RemoveSymbOfNewStr(string);
    for (int i = 0; i < amount_of_commands; i++)
    {
        if (i == atoi(string))
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
            return i;
    }
    return -1;
}

void RemoveSymbOfNewStr(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] =='\n')
            string[i - 1] = '\0';
    }
}

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

spu_t SpuInit(stack_t *stk)
{
    spu_t spu = {};
    spu.stack = stk;
    spu.ip = 0;
    spu.regs = regs;
    int* steps = (int*)calloc(CAPACITY, sizeof(int));
    spu.steps = steps;
    return spu;
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

void StackPush(stack_t *stk, int num)
{
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

void Popr(stack_t *stk, int reg)
{
    regs[reg] = stk->data[stk->size];
    stk->size--;
}

void StackPop(stack_t *stk, int n)
{
    StackVerify(stk);

    int size = stk->size;
    int *data = stk->data;
    int capacity = stk->capacity;

    printf("last number from stack: %d\n", data[size]);
    stk->data[size] = 0;
    stk->size--;
}

void Pushr(stack_t *stk, int reg)
{
    regs[reg] = 0;
}

void StackDump(stack_t *stk) 
{
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

void StackDestroy(stack_t *stk, int n)
{
    StackVerify(stk);
    
    free(stk->data);
    stk->data = NULL;
}

void AddNumbers(stack_t *stk, int n)
{
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
    /*stk->data[stk->size + 1] = 0; просто делает стек читабельнее (наверное, нуу мне так кажется) 
    стоит ли оставлять, если пользователь все равно не видит стек?*/
}

void DifferenceOfNumbers(stack_t *stk, int n)
{
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

void QuotientOfNumbers(stack_t *stk, int n)
{
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

void MultiplyingNumbers(stack_t *stk, int n)
{
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

void SquareRootOfNumber(stack_t *stk, int n)
{
    StackVerify(stk);
    stk->data[stk->size] = sqrt(stk->data[stk->size]);
}

void OutputForUser(stack_t *stk)
{
    StackVerify(stk);
    StackErr_t err = stk->error;
    if (err != NO_ERRORS)
        printf("%s\n", ArrayOfErrors[err].description);
}