const int CAPACITY = 10;
const int SIZE_OF_REG = 16;
const int MAX_SIZE_OF_CODE = 100000;

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

void StackInit(stack_t *stk, const int CAPACITY);
spu_t SpuInit(stack_t *stk);
bool StackVerify(stack_t *stk, int prm = -1);
int LooksForNumInStringForAsm(char* str, int* numm);
void FillSpu(spu_t* spu, char* inf);