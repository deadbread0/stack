#ifndef FOR_TYPES
#include "types.h"
#endif
                             

void StackInit(stack_t *stk, const int CAPACITY);
void SpuInit(stack_t *stk, spu_t *spu);
void ProgramForTerminalInput(spu_t* spu);
void ProgramForFileInput(spu_t* spu, const char* filee_name);