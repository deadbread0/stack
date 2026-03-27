#include <stdio.h>
#include <assert.h>
#include "input_and_output_mc.h"

//extern int* arr_of_steps;
void OutputInFile(int i, arr_t* struct_arr)
{
    /*FILE* output_file = fopen("datasm", "w"); если я пытаюсь открыть файл, программа зависает...((
    а так то вывод должен быть в файл, но пока есть только в терминал*/
    int sum = 0;
    int* arr_of_steps = struct_arr->arr_of_steps;
    int* arr = struct_arr->arr;
    printf("%d\n", i);
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
        // printf("2");

        int counterr = 0, check_len = 0;
        size_t buff_size = MAX_LEN_OF_WORD;
        while (check_len != -1)
        {
            char *lineptr = (char *)calloc(buff_size, sizeof(char));
            // printf("q");
            // check_len = MyOwnGetline(&lineptr, &buff_size, filee);
            lineptr = fgets(lineptr, buff_size, filee);
            // printf("w");
            inf[counterr] = lineptr;
            counterr++;
            if (!lineptr)
                check_len = -1;
            // printf("%d\n", check_len);
        }
        *amount_of_str = counterr;
        // printf("3");
    }

}

bool OpenAndCheckFileForReading(FILE** filee, const char* filee_name)//
{
    *filee = fopen(filee_name, "rb");
    if (*filee == nullptr)
    {
        printf("File %s didn't open((\n", filee_name);
        return false;
    }
    return true;
}