
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
};

enum WasFileRead {
    NO,
    YES
};

void ProgramForTerminalInput(spu_t* spu);
void ProgramForFileInput(spu_t* spu, const char* filee_name);
bool Input(spu_t* spu);
void Canary(stack_t *stk);
void OutputForUser(stack_t *stk);
bool StackVerify(stack_t *stk, int prm = -1);
void StackDump(spu_t* spu);
void StackDestroy(spu_t* spu, int n = NULL);
WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
void InputFromFile(FILE* filee, spu_t* spu);
bool RunFuncForAsm(spu_t* spu);