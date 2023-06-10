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

    RetInst* Builder::CreateRet()
    {
        RetInst* ret = new RetInst(m_InsertPoint);

        m_InsertPoint->insertInstruction(ret);

        return ret;
    }
}