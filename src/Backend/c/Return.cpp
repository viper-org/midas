// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/RetInst.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileRet(std::stringstream& buffer, RetInst* ret)
        {
            buffer << "return ";
            compileValue(buffer, ret->getReturnValue());
            buffer << ";\n";
        }
    }
}