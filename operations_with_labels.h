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

bool StackVerify(stack_t *stk, int prm = -1);
void JumpIfBelow(spu_t* spu, int num);
void FillSpuForJump(spu_t* spu, int num);
void JumpIfBelowOrEqual(spu_t* spu, int num);
void JumpIfAbove(spu_t* spu, int num);
void JumpIfAboveOrEqual(spu_t* spu, int num);
void JumpIfEqual(spu_t* spu, int num);
void JumpIfNotEqual(spu_t* spu, int num);