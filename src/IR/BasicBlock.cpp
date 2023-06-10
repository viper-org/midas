// Copyright 2023 solar-mist


#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <midas/Module.h>
#include <format>

namespace midas
{
    BasicBlock* BasicBlock::Create(std::string name, Function* parent)
    {
        if(name.empty())
            name = std::to_string(parent->getInstNo()++);
        BasicBlock* bb = new BasicBlock(std::move(name), parent);

        parent->insertBasicBlock(bb);

        return bb;
    }

    void BasicBlock::print(std::stringstream& stream) const
    {
        stream << std::format("{}:\n", m_Name);
    }

    BasicBlock::BasicBlock(std::string name, Function* parent)
        :Value(parent->getModule()), m_Name(std::move(name)), m_Parent(parent)
    {
    }
}