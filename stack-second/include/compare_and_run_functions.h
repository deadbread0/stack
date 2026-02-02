#ifndef FOR_TYPES
#include "types.h"
#endif  

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
void Popm(spu_t* spu, int num_of_name);
void Pushm(spu_t* spu, int num_of_name);
void TssStackPop(spu_t* spu, int n = 0);


commands_t ArrayOfCommands[] = {{"push ", StackPush, "pushing a number onto the stack"},
                                {"add", AddNumbers, "adding numbers"},
                                {"sub", DifferenceOfNumbers, "number difference"},
                                {"div", QuotientOfNumbers, "quotient of numbers"},
                                {"mul", MultiplyingNumbers, "multiplying numbers"},
                                {"sqrt", SquareRootOfNumber, "square root calculation"},
                                {"out", StackPop, "returns the value removed from the stack"},
                                {"hlt", StackDestroy, "ends the loop"},
                                {"pushr ", Popr, "delete number from register"},
                                {"popr", Pushr, "push number in register"},
                                {":", FillLabels, "add label to array"},
                                {"jb", JumpIfBelow, "jump if last number is less than practically last"},
                                {"jbe", JumpIfBelowOrEqual, "jump if last number is less or equal than practically last"},
                                {"ja", JumpIfAbove, "jump if last number is bigger than practically last"},
                                {"jae", JumpIfAboveOrEqual, "jump if last number is bigger or equal than practically last"},
                                {"je", JumpIfEqual, "jump if last number is equal to practically last"},
                                {"jne", JumpIfNotEqual, "jump if last number is not equal to practically last"},
                                {"popm", Pushm, "add number of variable in ram"},
                                {"pushm", Popm, "delete number of variable from ram"},
                                {"pop ", TssStackPop, "delete last elem from stsck"}};//pop = out

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

