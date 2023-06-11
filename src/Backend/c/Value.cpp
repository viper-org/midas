// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/Value.h>
#include <midas/IR/ConstantInt.h>
#include <midas/IR/LoadInst.h>

namespace midas
{
    namespace backend
    {
        void compileValue(std::stringstream& buffer, Value* value)
        {
            if(dynamic_cast<ConstantInt*>(value))
                compileConstantInt(buffer, dynamic_cast<ConstantInt*>(value));
            else if(dynamic_cast<LoadInst*>(value))
                compileLoad(buffer, dynamic_cast<LoadInst*>(value));
        }
    }
}