const int MAX_LEN_OF_WORD = 100;
const int first_reg_command = 8;

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

struct spu_t {
    int* code;
    stack_t* stack;
    int ip;
    int* steps;
    int amount_of_steps;
    int* regs;
    int* labels;
};

typedef void (*function_ptr)(spu_t*, int); 

struct commands_t {
    const char* command;
    function_ptr pt;
    const char* description;
};  

void StackPush(spu_t* spu, int num);
void StackDestroy(spu_t* spu, int n = NULL);
void StackPop(spu_t* spu, int n = NULL);
void AddNumbers(spu_t* spu, int n = NULL);
void DifferenceOfNumbers(spu_t* spu, int n = NULL);
void QuotientOfNumbers(spu_t* spu, int n = NULL);
void MultiplyingNumbers(spu_t* spu, int n = NULL);
void SquareRootOfNumber(spu_t* spu, int n = NULL);
void Popr(spu_t* spu, int num);
void Pushr(spu_t* spu, int reg);
void FillLabels(spu_t* spu, int n);
void JumpIfBelow(spu_t* spu, int num);
void JumpIfBelowOrEqual(spu_t* spu, int num);
void JumpIfAbove(spu_t* spu, int num);
void JumpIfAboveOrEqual(spu_t* spu, int num);
void JumpIfEqual(spu_t* spu, int num);
void JumpIfNotEqual(spu_t* spu, int num);
void StackDump(spu_t* spu);

commands_t ArrayOfCommands[] = {{"push ", StackPush, "pushing a number onto the stack"},
                                {"add", AddNumbers, "adding numbers"},
                                {"sub", DifferenceOfNumbers, "number difference"},
                                {"div", QuotientOfNumbers, "quotient of numbers"},
                                {"mul", MultiplyingNumbers, "multiplying numbers"},
                                {"sqrt", SquareRootOfNumber, "square root calculation"},
                                {"out", StackPop, "returns the value removed from the stack"},
                                {"hlt", StackDestroy, "ends the loop"},
                                {"popr ", Popr, "add number in register"},
                                {"pushr", Pushr, "delete number from register"},
                                {":", FillLabels, "add label to array"},
                                {"jb", JumpIfBelow, "jump if last number is less than practically last"},
                                {"jbe", JumpIfBelowOrEqual, "jump if last number is less or equal than practically last"},
                                {"ja", JumpIfAbove, "jump if last number is bigger than practically last"},
                                {"jae", JumpIfAboveOrEqual, "jump if last number is bigger or equal than practically last"},
                                {"je", JumpIfEqual, "jump if last number is equal to practically last"},
                                {"jne", JumpIfNotEqual, "jump if last number is not equal to practically last"}};

const int amount_of_commands = sizeof(ArrayOfCommands)/sizeof(ArrayOfCommands[0]);

const int num_of_hlt = 7;

bool StackVerify(stack_t *stk, int prm = -1);
int CompareStringWithCommand(char *string);
int LooksForNumInString(char* str, int* numm);
int LooksForReg(char* str);
void RemoveSymbOfNewStr(char *string);
bool RunFunc(spu_t* spu, char* inf);
bool RunFuncForMC(spu_t* spu);


const int len_for_strncmp = strlen("pushr");

