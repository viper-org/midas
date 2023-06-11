// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/Instruction.h>
#include <midas/IR/RetInst.h>
#include <midas/IR/Alloca.h>
#include <midas/IR/LoadInst.h>
#include <midas/IR/StoreInst.h>

namespace midas
{
    namespace backend
    {
        void compileInstruction(std::stringstream& buffer, Instruction* inst)
        {
            if(dynamic_cast<RetInst*>(inst))
                compileRet(buffer, dynamic_cast<RetInst*>(inst));
            else if(dynamic_cast<AllocaInst*>(inst))
                compileAlloca(buffer, dynamic_cast<AllocaInst*>(inst));
            else if(dynamic_cast<StoreInst*>(inst))
                compileStore(buffer, dynamic_cast<StoreInst*>(inst));
        }
    }
}