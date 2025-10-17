const int CAPACITY = 10;
const int MAX_LEN_OF_WORD = 100;
const int LEFT_CONSTANT = 0xFEDCBA;
const int RIGHT_CONSTANT = 0xFEDCBA;
const int MAX_SIZE_ARR = 1000;
const int SIZE_OF_REG = 16;

int arr[MAX_SIZE_ARR] = {0}, arr_of_steps[MAX_SIZE_ARR] = {0};

enum WasFileRead {
    NO,
    YES
};
                             
int CompareStringWithCommand(char *string);
int LooksForNumInString(char* str, int* numm);
void RemoveSymbOfNewStr(char *string);
bool Push(char** inf, int i, int* sum_of_steps);
void ProgrammForFileInput(const char* filee_name, char ** inf, int* amount_of_str);
WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr);
void OutputInFile(int* arr, int i);
int LooksForReg(char* str);



const char *ArrayOfCommands[] = {"push ", "add", "sub", "div", "mul", "sqrt", "out", "hlt", "popr ", "pushr"};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);
const int first_reg_command = 8;
const int len_for_strncmp = strlen("pushr");