#include <cstdio>
#ifndef FOR_TYPES
#include "types.h"
#endif

void ProgramForTerminalInput(spu_t* spu);
void ProgramForFileInput(spu_t* spu, const char* filee_name);
bool Input(spu_t* spu);
void Canary(stack_t *stk);
void OutputForUser(stack_t *stk);
bool StackVerify(stack_t *stk, int prm = -1);
void StackDump(spu_t* spu);
void StackDestroy(spu_t* spu, int n = NULL);
WasFileRead OpenAndCheckFileForReading(FILE** filee, const char* filee_name);
void InputFromFile(FILE* filee, spu_t* spu, int size);
bool RunFuncForMC(spu_t* spu);
int GetSizeOfInputFile(const char* file_name);
void FillSteps(spu_t* spu);
void FindJumpsAndFillLabels(spu_t* spu);
