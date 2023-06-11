// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/ConstantInt.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileConstantInt(std::stringstream& buffer, ConstantInt* constant)
        {
            buffer << std::to_string(constant->getValue());
        }
    }
}