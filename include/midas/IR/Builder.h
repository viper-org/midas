// Copyright 2023 solar-mist

/*
 * A builder is the object used to create IR objects
 * such as instructions
*/

#ifndef MIDAS_IR_BUILDER_H
#define MIDAS_IR_BUILDER_H 1
#include <midas/IR/BasicBlock.h>
#include <midas/IR/RetInst.h>

namespace midas
{
    class Builder
    {
    public:
        Builder();

        void setInsertPoint(BasicBlock* newInsertPoint);

        RetInst* CreateRet();
    private:
        BasicBlock* m_InsertPoint;
    };
}

#endif // MIDAS_IR_BUILDER_H