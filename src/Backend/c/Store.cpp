// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/StoreInst.h>
#include <midas/IR/Alloca.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileStore(std::stringstream& buffer, StoreInst* store)
        {
            if(dynamic_cast<AllocaInst*>(store->getPointer()))
            {
                buffer << std::format("L{} = ", dynamic_cast<AllocaInst*>(store->getPointer())->getName());
                compileValue(buffer, store->getValue());
                buffer << ";\n";
            }
        }
    }
}