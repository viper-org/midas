// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/BasicBlock.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileBasicBlock(std::stringstream& buffer, BasicBlock* bb)
        {
            if(bb->getNoBranches())
                buffer << std::format("L{}:\n", bb->getName());

            for(Instruction* inst : bb->getInstructions())
                compileInstruction(buffer, inst);
        }
    }
}