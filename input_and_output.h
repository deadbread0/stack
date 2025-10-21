const int MAX_LEN_OF_WORD = 100;

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

struct spu_t {
    int* code;
    stack_t* stack;
    int ip;
    int* steps;
    int amount_of_steps;
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

bool StackVerify(stack_t *stk, int prm = -1);
bool RunFunc(spu_t* spu, char* inf);
void FillSpu(spu_t* spu, char* inf);
bool Input(spu_t* spu);
void InputFromFile(FILE* filee, spu_t* spu);