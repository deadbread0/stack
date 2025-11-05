#include <stdio.h>
#include "fill_arrays_mc.h"


bool FillArrays(char** inf, int i, int* sum_of_steps, arr_t* arr_struct)
{
    int numm = 0, counter = 0;
    bool prm_there = false;

    if (*(inf + i) == nullptr)
        return false;

    int num_of_func = CompareStringWithCommand(*(inf + i));
    
        if (num_of_func == 0 || num_of_func >= 10)
        {
            arr_struct->arr[i + *sum_of_steps] = num_of_func;
            prm_there = LooksForNumInString(*(inf + i), &numm);
            if (prm_there == true)
            {
                arr_struct->arr_of_steps[i] = 2;
                (*sum_of_steps)++;
                arr_struct->arr[i + *sum_of_steps] = numm;
            }
            else
                arr_struct->arr_of_steps[i] = 1;
            return true;
        }
        else if (num_of_func > 0 && num_of_func < first_reg_command)
        {
            arr_struct->arr[i + *sum_of_steps] = num_of_func;
            arr_struct->arr_of_steps[i] = 1;
            return true;
        }
        else if (num_of_func >= first_reg_command && num_of_func < 10)///
        {
            arr_struct->arr[i + *sum_of_steps] = num_of_func;
            counter = LooksForReg(*(inf + i));
            if (counter >= 0)
            {
                arr_struct->arr_of_steps[i] = 2;
                (*sum_of_steps)++;
                arr_struct->arr[i + *sum_of_steps] = numm;
            }
            return true;
        }
        return false;
}
