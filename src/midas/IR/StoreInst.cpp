// Copyright 2023 solar-mist


#include <midas/IR/StoreInst.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <format>

namespace midas
{
    Value* StoreInst::getPointer() const
    {
        return m_Ptr;
    }

    Value* StoreInst::getValue() const
    {
        return m_Value;
    }

    void StoreInst::print(std::stringstream& stream) const
    {
        m_Value->print(stream);
        stream << std::format("store i32 {}, i32* {}\n", m_Value->ident(), m_Ptr->ident());
    }

    std::string StoreInst::ident() const
    {
        return "%undef";
    }

    StoreInst::StoreInst(BasicBlock* parent, Value* ptr, Value* value)
        :Instruction(parent->getParent()->getModule()), m_Ptr(ptr), m_Value(value)
    {
    }
}