
struct arr_t {
    int* arr;
    int* arr_of_steps;
};

bool FillArrays(char** inf, int i, int* sum_of_steps, arr_t*);
int CompareStringWithCommand(char *string);
bool LooksForNumInString(char* str, int* numm);
int LooksForReg(char* str);
const int first_reg_command = 8;
