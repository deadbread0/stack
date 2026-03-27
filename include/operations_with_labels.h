#ifndef FOR_TYPES
#include "types.h"
#endif

bool StackVerify(stack_t *stk, int prm = -1);
void JumpIfBelow(spu_t* spu, int num);
void FillSpuForJump(spu_t* spu, int num);
void JumpIfBelowOrEqual(spu_t* spu, int num);
void JumpIfAbove(spu_t* spu, int num);
void JumpIfAboveOrEqual(spu_t* spu, int num);
void JumpIfEqual(spu_t* spu, int num);
void JumpIfNotEqual(spu_t* spu, int num);
void Popm(spu_t* spu, int num_of_name);
void Pushm(spu_t* spu, int num_of_name);