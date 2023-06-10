// Copyright 2023 solar-mist


#include <Backend/c/Function.h>
#include <midas/IR/Function.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileFunction(std::stringstream& buffer, Function* func)
        {
            buffer << std::format("int {}() {{\n", func->getName());
            
            buffer << "}\n";
        }
    }
}