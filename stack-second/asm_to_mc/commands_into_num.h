const int CAPACITY = 10;
const int MAX_LEN_OF_WORD = 100;
const int LEFT_CONSTANT = 0xFEDCBA;
const int RIGHT_CONSTANT = 0xFEDCBA;
const int MAX_SIZE_ARR = 1000;
const int SIZE_OF_REG = 16;

struct arr_t {
    int* arr;
    int* arr_of_steps;
};
                             
bool FillArrays(char** inf, int i, int* sum_of_steps, arr_t*);
void ProgrammForFileInput(const char* filee_name, char ** inf, int* amount_of_str);
void OutputInFile(int i, arr_t* struct_arr);