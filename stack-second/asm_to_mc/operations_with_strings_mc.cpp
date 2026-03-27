#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include "operations_with_strings_mc.h"

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

ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr)
{
    char ch = 0, i = 0;
    char *buff = *lineptr;
    if (filestr == nullptr)
        return -1;
    // fgets
    // while ((ch = getc(filestr)) != '\n' && ch != EOF)
    // {
    //     printf(",%c, ", ch);
    //     if ((int)*buff_size < i + 1)
    //     {
    //         char *new_buff = (char*) realloc(buff, sizeof(char) * (*buff_size) * 2);
    //         if (new_buff = nullptr)
    //         {
    //             return i;
    //         }
    //     }
    //     *(buff + i) = ch;
    //     i++;
    // }
    // *buff_size = strlen(buff);
    // char *new_new_buff = (char*)realloc(buff, sizeof(char) * (*buff_size) * 2);
    // *(buff + i) = '\n';
    // *(buff + i + 1) = '\0';
    // *lineptr = buff;
    // printf("%d ", i);
    // if (i == 0)
    //     return -1;
    // else
    //     return i;
    
}

bool LooksForNumInString(char* str, int* numm)
{
    int i = 1;//
    int num = 0, counter = 0, sign = 1, colon = 0;
    int num_of_command = atoi(str);
    while (num_of_command > 0)
    {
        i++;
        num_of_command = num_of_command / 10;
    }

    while (str[i] != '\0')
    {
        if (str[i] == '-')
            sign = -1;
        if (str[i] == ':')
            colon++;
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
        *numm = num * sign;
        return true;
    }
    return false;
}

int CompareStringWithCommand(char *string)
{
    RemoveSymbOfNewStr(string);
    int len = strlen(string);
    if (len > len_for_strncmp)
        len = len_for_strncmp;
    if (len < len_for_strncmp && len > 1)
        len = 3;//
    if (string[0] == ':')
        len = 1;///
    for (int i = 0; i < amount_of_commands; i++)
    {
        if (strncmp(string, ArrayOfCommands[i], len) == 0)
        {
            return i;
        }
        if (strncmp(string, "popm", 4) == 0)
        {
            return 17;
        }
        if (strncmp(string, "je", 2) == 0)
        {
            return 15;
        }
        if (strncmp(string, "jne", 3) == 0)
        {
            return 16;
        }
        if (strncmp(string, "pop", 3) == 0)
        {
            return 19;
        }
    }
    printf("%s", string);
    return -1;
}