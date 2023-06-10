// Copyright 2023 solar-mist


#include <midas/IR/RetInst.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <format>

namespace midas
{
    Value* RetInst::getReturnValue() const
    {
        return m_ReturnValue;
    }

    void RetInst::print(std::stringstream &stream) const
    {
        m_ReturnValue->print(stream);
        stream << std::format("ret i32 {}", m_ReturnValue->ident());
    }

    std::string RetInst::ident() const
    {
        return "%undef";
    }

    RetInst::RetInst(BasicBlock* parent, Value* returnValue)
        :Instruction(parent->getParent()->getModule()), m_ReturnValue(returnValue)
    {
    }
}