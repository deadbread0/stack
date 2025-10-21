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

struct spu_t {
    int* code;
    stack_t* stack;
    int ip;
    int* steps;
    int amount_of_steps;
    int* regs;
};

struct stack_err_t {
    StackErr_t type;
    const char* description;
};



void AddNumbers(spu_t* spu, int n = NULL);
void DifferenceOfNumbers(spu_t* spu, int n = NULL);
void QuotientOfNumbers(spu_t* spu, int n = NULL);
void MultiplyingNumbers(spu_t* spu, int n = NULL);
void SquareRootOfNumber(spu_t* spu, int n = NULL);
bool StackVerify(stack_t *stk, int prm = -1);
void StackPush(spu_t* spu, int num);
void StackDump(spu_t* spu);
void StackDestroy(spu_t* spu, int n = NULL);
void StackPop(spu_t* spu, int n = NULL);