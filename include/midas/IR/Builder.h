// Copyright 2023 solar-mist

/*
 * A builder is the object used to create IR objects
 * such as instructions
*/

#ifndef MIDAS_IR_BUILDER_H
#define MIDAS_IR_BUILDER_H 1
#include <midas/IR/BasicBlock.h>
#include <midas/IR/RetInst.h>
#include <midas/IR/Alloca.h>
#include <midas/IR/LoadInst.h>
#include <midas/IR/StoreInst.h>
#include <midas/IR/ConstantInt.h>

namespace midas
{
    class Builder
    {
    public:
        Builder();

        void setInsertPoint(BasicBlock* newInsertPoint);

        RetInst* CreateRet(Value* returnValue);
        AllocaInst* CreateAlloca(std::string name);
        LoadInst* CreateLoad(Value* ptr, std::string name);
        StoreInst* CreateStore(Value* ptr, Value* value);

        ConstantInt* CreateConstantInt(uint64_t value);
    private:
        BasicBlock* m_InsertPoint;
    };
}

#endif // MIDAS_IR_BUILDER_H