#ifndef FOR_TYPES
#include "types.h"
#endif

void AddNumbers(spu_t* spu, int n = 0);
void DifferenceOfNumbers(spu_t* spu, int n = 0);
void QuotientOfNumbers(spu_t* spu, int n = 0);
void MultiplyingNumbers(spu_t* spu, int n = 0);
void SquareRootOfNumber(spu_t* spu, int n = 0);
bool StackVerify(stack_t *stk, int prm = -1);
void StackPush(spu_t* spu, int num);
void StackDump(spu_t* spu);
void StackDestroy(spu_t* spu, int n = 0);
void StackPop(spu_t* spu, int n = 0);
void TssStackPop(spu_t* spu, int n = 0);
