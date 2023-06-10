// Copyright 2023 solar-mist


#include <midas/IR/Builder.h>

namespace midas
{
    Builder::Builder()
    {
    }

    void Builder::setInsertPoint(BasicBlock* newInsertPoint)
    {
        m_InsertPoint = newInsertPoint;
    }

    RetInst* Builder::CreateRet(Value* returnValue)
    {
        RetInst* ret = new RetInst(m_InsertPoint, returnValue);

        m_InsertPoint->insertInstruction(ret);

        return ret;
    }

    ConstantInt* Builder::CreateConstantInt(uint64_t value)
    {
        return new ConstantInt(m_InsertPoint, value);
    }
}