const int CAPACITY = 10;
const int MAX_LEN_OF_WORD = 100;
const int LEFT_CONSTANT = 0xFEDCBA;
const int RIGHT_CONSTANT = 0xFEDCBA;
const int SIZE_OF_REG = 16;
const int first_reg_command = 8;
const int len_for_strncmp = strlen("pushr");

int regs[SIZE_OF_REG] = {0};

enum StackErr_t {
    NO_ERRORS,
    MEMORY_ALLOCATION,
    NULLPTR,
    CAPACITY_LESS_THAN_SIZE,
    CAPACITY_OR_SIZE_LESS_THAN_ZERO,
    NO_PARAMETER, 
    ATTACK_FROM_THE_LEFT,
    ATTACK_FROM_THE_RIGHT,
    ERROR_COMAND
};

struct stack_t {
    int* data;
    int size;
    int capacity;
    StackErr_t error;
};

struct stack_err_t {
    StackErr_t type;
    const char* description;
};

enum WasFileRead {
    NO,
    YES
};

struct spu_t {
    int* code;
    stack_t* stack;
    int ip;
    int* steps;
    int* regs;
};

stack_err_t ArrayOfErrors[] = {{NO_ERRORS, "no errors"},
                               {MEMORY_ALLOCATION, "memory allocation error"},
                               {NULLPTR, "null pointer detected"},
                               {CAPACITY_LESS_THAN_SIZE, "capacity less than size"},
                               {CAPACITY_OR_SIZE_LESS_THAN_ZERO, "capacity or size less than zero (not enough numbers in stack)"},
                               {NO_PARAMETER, "parameter was not entered"},
                               {ATTACK_FROM_THE_LEFT, "problems with stack"},
                               {ATTACK_FROM_THE_RIGHT, "problems with stack"},
                               {ERROR_COMAND, "you entered a non-existent command"}};

typedef void (*function_ptr)(stack_t*, int);   

struct commands_t {
    const char* command;
    function_ptr pt;
    const char* description;
};                               

void StackInit(stack_t *stk, const int CAPACITY);
spu_t SpuInit(stack_t *stk);
void StackPush(stack_t *stk, int num);
void StackDump(stack_t *stk);
void StackDestroy(stack_t *stk, int n = NULL);
void StackPop(stack_t *stk, int n = NULL);
bool StackVerify(stack_t *stk, int prm = -1);
bool Input(stack_t *stk);
int CompareStringWithCommand(char *string);
int LooksForNumInString(char* str, int* numm);
void AddNumbers(stack_t *stk, int n = NULL);
void DifferenceOfNumbers(stack_t *stk, int n = NULL);
void QuotientOfNumbers(stack_t *stk, int n = NULL);
void MultiplyingNumbers(stack_t *stk, int n = NULL);
void SquareRootOfNumber(stack_t *stk, int n = NULL);
void Canary(stack_t *stk);
bool RunFunc(stack_t *stk, char* inf);
void OutputForUser(stack_t *stk);
WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
bool InputFromFile(FILE* filee, spu_t* spu);
void RemoveSymbOfNewStr(char *string);
void ProgrammForTerminalInput(stack_t *stk);
void ProgrammForFileInput(spu_t* spu, const char* filee_name);
int CompareStringWithCommandForAsm(char *string);
int LooksForNumInStringForAsm(char* str, int* numm);
bool RunFuncForAsm(stack_t *stk, char* inf);
int LooksForReg(char* str);
void Popr(stack_t *stk, int num);
void Pushr(stack_t *stk, int reg);

commands_t ArrayOfCommands[] = {{"push ", StackPush, "pushing a number onto the stack"},
                                {"add", AddNumbers, "adding numbers"},
                                {"sub", DifferenceOfNumbers, "number difference"},
                                {"div", QuotientOfNumbers, "quotient of numbers"},
                                {"mul", MultiplyingNumbers, "multiplying numbers"},
                                {"sqrt", SquareRootOfNumber, "square root calculation"},
                                {"out", StackPop, "returns the value removed from the stack"},
                                {"hlt", StackDestroy, "ends the loop"},
                                {"popr ", Popr, "add number in register"},
                                {"pushr", Pushr, "delete number from register"}};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);//
const int num_of_hlt = 7;