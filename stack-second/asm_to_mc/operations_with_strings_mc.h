const int SIZE_OF_REG = 16;

void RemoveSymbOfNewStr(char *string);
int LooksForReg(char* str);
ssize_t MyOwnGetline(char **lineptr, size_t *buff_size, FILE *filestr);
bool LooksForNumInString(char* str, int* numm);

const int len_for_strncmp = strlen("pushr");
const char *ArrayOfCommands[] = {"push ", "add", "sub", "div", "mul", "sqrt", "out", "hlt", "popr ", "pushr", ":", "jb ", "jbe ", "ja ", "jae ", "je ", "jne ", "popm", "pushm", "pop "};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);
