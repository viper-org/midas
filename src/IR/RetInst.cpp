// Copyright 2023 solar-mist


#include <midas/IR/RetInst.h>
#include <midas/IR/BasicBlock.h>
#include <midas/IR/Function.h>

namespace midas
{
    void RetInst::print(std::stringstream &stream) const
    {
        stream << "ret i32 0";
    }

    RetInst::RetInst(BasicBlock* parent)
        :Instruction(parent->getParent()->getModule())
    {
    }
}