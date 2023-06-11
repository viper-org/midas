// Copyright 2023 solar-mist


#include <midas/IR/Alloca.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <format>

namespace midas
{
    std::string_view AllocaInst::getName() const
    {
        return m_Name;
    }

    void AllocaInst::print(std::stringstream& stream) const
    {
        stream << std::format("%{} = alloca i32", m_Name);
    }

    std::string AllocaInst::ident() const
    {
        return std::format("%{}", m_Name);
    }

    AllocaInst::AllocaInst(BasicBlock* parent, std::string name)
        :Instruction(parent->getParent()->getModule()), m_Name(name)
    {
    }
}