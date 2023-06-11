// Copyright 2023 solar-mist


#include <midas/IR/Builder.h>
#include <midas/IR/Function.h>

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

    AllocaInst* Builder::CreateAlloca(std::string name)
    {
        if(name.empty())
            name = std::to_string(m_InsertPoint->getParent()->getInstNo()++);

        AllocaInst* alloca = new AllocaInst(m_InsertPoint, std::move(name));

        m_InsertPoint->insertInstruction(alloca);

        return alloca;
    }

    LoadInst* Builder::CreateLoad(Value* ptr, std::string name)
    {
        if(name.empty())
            name = std::to_string(m_InsertPoint->getParent()->getInstNo()++);

        return new LoadInst(m_InsertPoint, ptr, std::move(name));
    }

    ConstantInt* Builder::CreateConstantInt(uint64_t value)
    {
        return new ConstantInt(m_InsertPoint, value);
    }
}