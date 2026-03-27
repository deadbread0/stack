#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "work_with_strings.h"

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

bool LooksForNumInString(char* str, int* numm)//bool
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

void RemoveSymbOfNewStr(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] =='\n')
            string[i - 1] = '\0';
    }
}