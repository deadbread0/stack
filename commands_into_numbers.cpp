/*программа переводит команды из файла в числа*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "commands_into_num.h"
int main(const int argc, const char* argv[])
{
    const char* filee_name = argc > 0? argv[1]: "";
    FILE* filee = nullptr;

    int amount_of_str = 0, sum_of_steps = 0, counter = 0;
    char* inf[MAX_SIZE_ARR] = {0};
    ProgrammForFileInput(filee_name, inf, &amount_of_str);
    bool prm_for_while = true;

    while(prm_for_while && counter < amount_of_str)
        prm_for_while = Push(inf, counter++, &sum_of_steps);

    OutputInFile(arr, counter);
    return 0;
}

void OutputInFile(int* arr, int i)
{
    /*FILE* output_file = fopen("datasm", "w"); если я пытаюсь открыть файл, программа зависает...((
    а так то вывод должен быть в файл, но пока есть только в терминал*/
    int sum = 0;
    for (int j = 0; j < i; j++)
    {
        if (arr_of_steps[j] == 1)
            printf("%d\n", arr[j + sum]);
        else if (arr_of_steps[j] == 2)
        {
            printf("%d ", arr[j + sum]);
            sum++;
            printf("%d\n", arr[j + sum]);
        }
    }
}

void ProgrammForFileInput(const char* filee_name, char ** inf, int* amount_of_str)
{
    FILE* filee = nullptr;
    if (!OpenAndCheckFileForReading(&filee, filee_name))
        return;
    else
    {
        int counterr = 0, check_len = 0;
        size_t buff_size = MAX_LEN_OF_WORD;
        while (check_len != -1)
        {
            char *lineptr = (char *)calloc(buff_size, sizeof(char));
            check_len = MyOwnGetline(&lineptr, &buff_size, filee);
            inf[counterr] = lineptr;
            counterr++;
        }
        *amount_of_str = counterr;
    }

}

ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr)
{
    char ch = 0, i = 0;
    char *buff = *lineptr;
    if (filestr == nullptr)
        return -1;
    while ((ch = getc(filestr)) != '\n' && ch != EOF)
    {
        if ((int)*buff_size < i + 1)
        {
            char *new_buff = (char*) realloc(buff, sizeof(char) * (*buff_size) * 2);
            if (new_buff = nullptr)
            {
                return i;
            }
        }
        *(buff + i) = ch;
        i++;
    }
    *buff_size = strlen(buff);
    char *new_new_buff = (char*)realloc(buff, sizeof(char) * (*buff_size) * 2);
    *(buff + i) = '\n';
    *(buff + i + 1) = '\0';
    *lineptr = buff;
    if (i == 0)
        return -1;
    else
        return i;
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

bool Push(char** inf, int i, int* sum_of_steps)
{
    int numm = 0, counter = 0;
    if (*(inf + i) == nullptr)
        return false;
    int num_of_func = CompareStringWithCommand(*(inf + i));
        if (num_of_func == 0)
        {
            arr[i + *sum_of_steps] = num_of_func;
            counter = LooksForNumInString(*(inf + i), &numm);
            if (counter > 0)
            {
                arr_of_steps[i] = 2;
                (*sum_of_steps)++;
                arr[i + *sum_of_steps] = numm;
            }
            else
                arr_of_steps[i] = 1;
            return true;
        }
        else if (num_of_func > 0 && num_of_func < first_reg_command)
        {
            arr[i + *sum_of_steps] = num_of_func;
            arr_of_steps[i] = 1;
            return true;
        }
        else if (num_of_func >= first_reg_command)
        {
            arr[i + *sum_of_steps] = num_of_func;
            counter = LooksForReg(*(inf + i));
            if (counter >= 0)
            {
                arr_of_steps[i] = 2;
                (*sum_of_steps)++;
                arr[i + *sum_of_steps] = numm;
            }
            return true;
        }
        return false;
}

int LooksForNumInString(char* str, int* numm)
{
    int i = 0;//
    int num = 0, counter = 0;
    while (str[i] != '\n')
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

int CompareStringWithCommand(char *string)
{
    RemoveSymbOfNewStr(string);
    int len = strlen(string);
    if (len > len_for_strncmp)
        len = len_for_strncmp;
    for (int i = 0; i < amount_of_commands; i++)
    {
        if (strncmp(string, ArrayOfCommands[i], len) == 0)
        {
            return i;
        }
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
