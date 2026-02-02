#include <cstdio>
#ifndef FOR_TYPES
#include "types.h"
#endif

bool StackVerify(stack_t *stk, int prm = -1);
bool RunFunc(spu_t* spu, char* inf);
void FillSpu(spu_t* spu, char* inf);
bool Input(spu_t* spu);
void InputFromFile(FILE* filee, spu_t* spu, int size);
void FillCode(spu_t* spu, char* data);
