#ifndef FOR_TYPES
#include "types.h"
#endif


void AddNumbers(spu_t* spu, int n = NULL);
void DifferenceOfNumbers(spu_t* spu, int n = NULL);
void QuotientOfNumbers(spu_t* spu, int n = NULL);
void MultiplyingNumbers(spu_t* spu, int n = NULL);
void SquareRootOfNumber(spu_t* spu, int n = NULL);
bool StackVerify(stack_t *stk, int prm = -1);
void FunctionForKillingCopyPaste(spu_t* spu, int* last, int* practically_last);
void QuietStackPop(spu_t* spu, int* n);
void StackPush(spu_t* spu, int num);
