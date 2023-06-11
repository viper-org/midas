// Copyright 2023 solar-mist

/*
 * Alloca is an instruction that allocates a section of
 * memory that fits a specific type
*/

#ifndef MIDAS_IR_ALLOCA_INST_H
#define MIDAS_IR_ALLOCA_INST_H 1
#include <midas/IR/Instruction.h>

namespace midas
{
    class Builder;
    class BasicBlock;
    class AllocaInst : public Instruction
    {
    friend class Builder;
    public:
        std::string_view getName() const;

        void print(std::stringstream& stream) const override;
        std::string ident() const override;
    private:
        AllocaInst(BasicBlock* parent, std::string name);

        std::string m_Name;
    };
}

#endif // MIDAS_IR_ALLOCA_INST_H