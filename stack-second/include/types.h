#define FOR_TYPES
static const int CAPACITY = 500;
static const int SIZE_OF_REG = 16;
static const int MAX_SIZE_OF_CODE = 100000;
static const int AMOUNT_OF_LABELS = 10;
static const int SIZE_OF_RAM = 100000;
static const int LEFT_CONSTANT = 0xFEDCBA;
static const int RIGHT_CONSTANT = 0xFEDCBA;
static const int MAX_LEN_OF_WORD = 100;
static const int first_reg_command = 8;
static const int MAX_AMOUNT_OF_VAR = 100;


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

struct stack_err_t {
    StackErr_t type;
    const char* description;
};

struct names_t
{
    int num_of_name;
    int value;
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
    int* ram;
    names_t* nametable;
};

enum WasFileRead {
    NO,
    YES
};

static stack_err_t ArrayOfErrors[] = {{NO_ERRORS, "no errors"},
                               {MEMORY_ALLOCATION, "memory allocation error"},
                               {NULLPTR, "null pointer detected"},
                               {CAPACITY_LESS_THAN_SIZE, "capacity less than size"},
                               {CAPACITY_OR_SIZE_LESS_THAN_ZERO, "capacity or size less than zero (not enough numbers in stack)"},
                               {NO_PARAMETER, "parameter was not entered"},
                               {ATTACK_FROM_THE_LEFT, "problems with stack (attack from the left)"},
                               {ATTACK_FROM_THE_RIGHT, "problems with stack (attack from the right)"},
                               {ERROR_COMAND, "you entered a non-existent command"}};

typedef void (*function_ptr)(spu_t*, int); 

struct commands_t {
    const char* command;
    function_ptr pt;
    const char* description;
};  