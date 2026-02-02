#ifndef FOR_TYPES
#include "types.h"
#endif

void StackInit(stack_t *stk, const int CAPACITY);
void SpuInit(stack_t *stk, spu_t *spu);
bool StackVerify(stack_t *stk, int prm = -1);
int LooksForNumInString(char* str, int* numm);
void FillSpu(spu_t* spu, char* inf);