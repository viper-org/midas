// Copyright 2023 solar-mist


#include <Backend/c/Compiler.h>
#include <midas/IR/LoadInst.h>
#include <midas/IR/Alloca.h>
#include <format>

namespace midas
{
    namespace backend
    {
        void compileLoad(std::stringstream& buffer, LoadInst* load)
        {
            if(dynamic_cast<AllocaInst*>(load->getPointer()))
                buffer << "L" << dynamic_cast<AllocaInst*>(load->getPointer())->getName();
        }
    }
}