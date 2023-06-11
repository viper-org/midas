// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/Alloca.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileAlloca(std::stringstream& buffer, AllocaInst* alloca)
        {
            buffer << std::format("int L{};\n", alloca->getName());
        }
    }
}