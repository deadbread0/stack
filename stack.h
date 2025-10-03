const int CAPACITY = 11;
const int MAX_LEN_OF_WORD = 100;
const int LEFT_CONSTANT = 0xFEDCBA;
const int RIGHT_CONSTANT = 0xFEDCBA;

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
bool InputFromFile(FILE* filee, stack_t *stk);
void RemoveSymbOfNewStr(char *string);

commands_t ArrayOfCommands[] = {{"push", StackPush, "pushing a number onto the stack"},
                                {"add", AddNumbers, "adding numbers"},
                                {"sub", DifferenceOfNumbers, "number difference"},
                                {"div", QuotientOfNumbers, "quotient of numbers"},
                                {"mul", MultiplyingNumbers, "multiplying numbers"},
                                {"sqrt", SquareRootOfNumber, "square root calculation"},
                                {"out", StackPop, "returns the value removed from the stack"},
                                {"hlt", StackDestroy, "ends the loop"}};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);//