const int CAPACITY = 10;
const int SIZE_OF_REG = 16;

int regs[SIZE_OF_REG] = {0};//так норм вообще делать?? Просто если я инициализирую в spuinit, то там массив мусором забивается((

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
                             

void StackInit(stack_t *stk, const int CAPACITY);
void SpuInit(stack_t *stk, spu_t *spu);
void ProgramForTerminalInput(spu_t* spu);
void ProgramForFileInput(spu_t* spu, const char* filee_name);