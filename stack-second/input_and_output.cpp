#include <stdio.h>
#include "include\input_and_output.h"
#include <ctype.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

bool Input(spu_t* spu)
{
    StackVerify(spu->stack);
    printf("enter the command and the value if necessary\n");
    char inf[MAX_LEN_OF_WORD] = {0};
    gets(inf);
    return RunFunc(spu, inf);
    
}

void InputFromFile(FILE* filee, spu_t* spu, int size)
{
    StackVerify(spu->stack);
    char* data = (char*)calloc(size + 1, sizeof(char));

    // fgets(inf, MAX_LEN_OF_WORD, filee);
    // while (*inf != 55 && *inf != EOF)///
    // {
    //     FillSpu(spu, inf);
    //     fgets(inf, MAX_LEN_OF_WORD, filee);
    // }
    fread(data, sizeof(char), size + 1, filee);
    FillCode(spu, data);

}

int GetSizeOfInputFile(const char* file_name)
{
    assert(file_name != nullptr);

    struct stat StructStat;
    stat(file_name, &StructStat);
    return StructStat.st_size;
}

void OutputForUser(stack_t *stk)
{
    StackVerify(stk);
    StackErr_t err = stk->error;
    if (err != NO_ERRORS)
        printf("%s\n", ArrayOfErrors[err].description);
}

void FillCode(spu_t* spu, char* data)
{
    int i = 0, i_code = 0;
    while (data[i] != '\0')
    {
        if ((data[i] <= '9' && data[i] >= '0') || data[i] == '-')
        {
            int num = 0;

            if (data[i] == '-')
            {
                i++;

                while (data[i] <= '9' && data[i] >= '0')
                {
                    num = num * 10 + (int)data[i] - '0';
                    i++;
                }
                spu->code[i_code] = num * (-1);
                i_code++;
                
                while (isspace(data[i]))
                {
                    i++;
                }

                continue;

            }

            while (data[i] <= '9' && data[i] >= '0')
            {
                num = num * 10 + (int)data[i] - '0';
                i++;
            }
            spu->code[i_code] = num;
            i_code++;
            
            while (isspace(data[i]))
            {
                i++;
            }
        }
    }

    spu->code[i_code] = '\0';
}

void FillSteps(spu_t* spu)
{
    int i = 0, i_steps = 0;
        // printf("(%d)", spu->code[i]);

    while (!(spu->code[i] == '\0' && spu->code[i + 1] == '\0' && spu->code[i + 2] == '\0' && spu->code[i + 3] == '\0' && spu->code[i + 4] == '\0'))
    {
        // printf("(%d)", spu->code[i]);
        if ((spu->code[i] == 0 || spu->code[i] >= 8) && spu->code[i] != 19)
        {
            i+=2;
            spu->steps[i_steps] = 2;
            i_steps++;
            continue;
        }

        i++;
        spu->steps[i_steps] = 1;
        i_steps++;
    }
    
}

void FillNameTable(spu_t* spu)
{

    int amount_of_func = 0;
    for (int i = 0; i < MAX_SIZE_OF_CODE; i++)
    {
        if (spu->steps[i] == 0)
        {
            amount_of_func = i;
            break;
        }
    }

    int i = 0, i_names = 0, c = -2;
    for (int i = 0; i < amount_of_func; i++)
    {
        int num_of_func = spu->code[spu->steps[i] + c];
        // printf("|%d|", num_of_func);//вдруг это будет важно, тут функция перед hlt неправильно выводится
        if (num_of_func == 17)
        {
            spu->nametable[i_names].num_of_name = i_names;
            spu->nametable[i_names].value = 0;
        }
        c += spu->steps[i];
    }
}