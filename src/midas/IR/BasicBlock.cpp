// Copyright 2023 solar-mist


#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>
#include <midas/IR/Instruction.h>
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

    Function* BasicBlock::getParent() const
    {
        return m_Parent;
    }

    const std::vector<Instruction*>& BasicBlock::getInstructions() const
    {
        return m_InstructionList;
    }

    void BasicBlock::insertInstruction(Instruction* instruction)
    {
        m_InstructionList.push_back(instruction);
    }

    void BasicBlock::print(std::stringstream& stream) const
    {
        stream << std::format("{}:\n", m_Name);
        for(Instruction* inst : m_InstructionList)
        {
            inst->print(stream);
            stream << "\n";
        }
    }

    std::string BasicBlock::ident() const
    {
        return std::format("%{}", m_Name);
    }

    BasicBlock::BasicBlock(std::string name, Function* parent)
        :Value(parent->getModule()), m_Name(std::move(name)), m_Parent(parent)
    {
    }
}