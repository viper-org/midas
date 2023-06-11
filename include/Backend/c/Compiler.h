// Copyright 2023 solar-mist

/*
 * Internal functions to compile specific IR to C code
*/

#ifndef MIDAS_BACKEND_BACKEND_C_COMPILER
#define MIDAS_BACKEND_BACKEND_C_COMPILER 1
#include <midas/Backend.h>

namespace midas
{
    class Function;
    class BasicBlock;
    class Value;
    class Instruction;
    class RetInst;
    class ConstantInt;

    namespace backend
    {
        void compileFunction(std::stringstream& buffer, Function* func);

        void compileBasicBlock(std::stringstream& buffer, BasicBlock* bb);
        void compileValue(std::stringstream& buffer, Value* value);
        void compileInstruction(std::stringstream& buffer, Instruction* inst);

        void compileRet(std::stringstream& buffer, RetInst* ret);

        void compileConstantInt(std::stringstream& buffer, ConstantInt* constant);
    }
}

#endif // MIDAS_BACKEND_BACKEND_C_COMPILER