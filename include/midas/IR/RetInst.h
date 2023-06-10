// Copyright 2023 solar-mist

/*
 * An instruction that returns from a function to its
 * caller
*/

#ifndef MIDAS_IR_RET_INST_H
#define MIDAS_IR_RET_INST_H 1
#include <midas/IR/Instruction.h>

namespace midas
{
    class Builder;
    class BasicBlock;
    class RetInst : public Instruction
    {
    friend class Builder;
    public:
        void print(std::stringstream& stream) const override;
    private:
        RetInst(BasicBlock* parent);
    };
}

#endif // MIDAS_IR_RET_INST_H