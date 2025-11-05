const int MAX_LEN_OF_WORD = 100;
const int MAX_SIZE_ARR = 1000;

struct arr_t {
    int* arr;
    int* arr_of_steps;
};

bool OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr);
bool OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
void OutputInFile(int i, arr_t* struct_arr);
