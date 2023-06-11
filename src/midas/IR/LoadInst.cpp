// Copyright 2023 solar-mist


#include <midas/IR/LoadInst.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <format>

namespace midas
{
    Value* LoadInst::getPointer() const
    {
        return m_Ptr;
    }

    void LoadInst::print(std::stringstream& stream) const
    {
        stream << std::format("%{} = load i32 {}\n", m_Name, m_Ptr->ident());
    }

    std::string LoadInst::ident() const
    {
        return std::format("%{}", m_Name);
    }

    LoadInst::LoadInst(BasicBlock* parent, Value* ptr, std::string name)
        :Instruction(parent->getParent()->getModule()), m_Ptr(ptr), m_Name(std::move(name))
    {
    }
}