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
    int arr[MAX_SIZE_ARR] = {0}, arr_of_steps[MAX_SIZE_ARR] = {0};
    arr_t struct_arr = {arr, arr_of_steps};

    // printf("1");
    ProgrammForFileInput(filee_name, inf, &amount_of_str);

    bool prm_for_while = true;

    while(prm_for_while && counter < amount_of_str)
        prm_for_while = FillArrays(inf, counter++, &sum_of_steps, &struct_arr);

    OutputInFile(counter, &struct_arr);
    return 0;
}











