#include <stdio.h>
#include "include\program_mode.h"

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
    bool prm_for_while1 = true, prm_for_while2 = true;
    FILE* filee = nullptr;

    if (!OpenAndCheckFileForReading(&filee, filee_name))
        return;

    int size = GetSizeOfInputFile(filee_name);
    InputFromFile(filee, spu, size);
    int counter = spu->ip + spu->amount_of_steps;
    spu->ip = 0;
    spu->amount_of_steps = 0;
    FillSteps(spu);
    FindJumpsAndFillLabels(spu);
    // for (int i = 0; i < 2 * size + 1; i++)
    // {
    //     printf(",%d, ", spu->code[i]);//7 не входит в steps
    // }

    while (prm_for_while1 && prm_for_while2) //while (prm_for_while1 && spu->ip < counter)
    {
        int ip = spu->ip;

        if (spu->steps[ip] == 0)
            break;

        prm_for_while2 = RunFuncForMC(spu);
        // printf("canary ");
        Canary(spu->stack);
        // printf("endcanary ");
        prm_for_while1 = StackVerify(spu->stack);
        // printf(" %d ", prm_for_while1);
        spu->ip++;
        spu->amount_of_steps = spu->amount_of_steps + spu->steps[ip] - 1;

    }

    OutputForUser(spu->stack);
    StackDump(spu);
    StackDestroy(spu);
}