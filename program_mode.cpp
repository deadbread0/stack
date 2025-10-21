#include <stdio.h>
#include "program_mode.h"

void ProgramForTerminalInput(spu_t* spu)
{
    bool prm_for_while = true, prm_for_while1 = true;
    while (prm_for_while && prm_for_while1)
    {
        prm_for_while = Input(spu);
        Canary(spu->stack);
        prm_for_while1 = StackVerify(spu->stack);
    }

    OutputForUser(spu->stack);
    StackDump(spu);
    StackDestroy(spu);
}

void ProgramForFileInput(spu_t* spu, const char* filee_name)
{
    bool prm_for_while = true, prm_for_while1 = true;
    FILE* filee = nullptr;

    if (!OpenAndCheckFileForReading(&filee, filee_name))
        return;

    InputFromFile(filee, spu);
    int *steps = spu->steps;
    int counter = spu->ip + spu->amount_of_steps;
    spu->ip = 0;
    spu->amount_of_steps = 0;

    while (prm_for_while1 && spu->ip < counter)
    {
        int ip = spu->ip;

        if (spu->steps[ip] == 0)
            break;

        RunFuncForAsm(spu);
        Canary(spu->stack);
        prm_for_while1 = StackVerify(spu->stack);
        spu->ip++;
        spu->amount_of_steps = spu->amount_of_steps + spu->steps[ip] - 1;

    }

    OutputForUser(spu->stack);
    StackDump(spu);
    StackDestroy(spu);
}