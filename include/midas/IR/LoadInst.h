// Copyright 2023 solar-mist

/*
 * An instruction that loads a value from a pointer
*/

#ifndef MIDAS_IR_LOAD_INST_H
#define MIDAS_IR_LOAD_INST_H 1
#include <midas/IR/Instruction.h>

namespace midas
{
    class Builder;
    class BasicBlock;
    class LoadInst : public Instruction
    {
    friend class Builder;
    public:
        Value* getPointer() const;

        void print(std::stringstream& stream) const override;
        std::string ident() const override;
    private:
        LoadInst(BasicBlock* parent, Value* ptr, std::string name);

        Value* m_Ptr;
        std::string m_Name;
    };
}

#endif // MIDAS_IR_LOAD_INST_H