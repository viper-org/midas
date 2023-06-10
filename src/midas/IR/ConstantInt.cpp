// Copyright 2023 solar-mist


#include <midas/IR/ConstantInt.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>

namespace midas
{
    void ConstantInt::print(std::stringstream&) const
    {
    }
    
    std::string ConstantInt::ident() const
    {
        return std::to_string(m_Value);
    }

    ConstantInt::ConstantInt(BasicBlock* parent, uint64_t value)
        :Constant(parent->getParent()->getModule()), m_Value(value)
    {
    }
}