const int CAPACITY = 10;
const int MAX_LEN_OF_WORD = 100;
const int LEFT_CONSTANT = 0xFEDCBA;
const int RIGHT_CONSTANT = 0xFEDCBA;
const int MAX_SIZE_ARR = 1000;

enum WasFileRead {
    NO,
    YES
};
                             
int CompareStringWithCommand(char *string);
int LooksForNumInString(char* str, int* numm);
void RemoveSymbOfNewStr(char *string);
bool Push(char** inf, int* arr, int* arr_of_steps, int i, int* sum_of_steps);
void ProgrammForFileInput(const char* filee_name, char ** inf, int* amount_of_str);
WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr);
void OutputInFile(int* arr, int* arr_of_steps, int i);



const char *ArrayOfCommands[] = {"push", "add", "sub", "div", "mul", "sqrt", "out", "hlt"};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);//