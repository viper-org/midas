// Copyright 2023 solar-mist

/*
 * Store is an instruction that sets the value inside a
 * pointer to a new value
*/

#ifndef MIDAS_IR_STORE_INST_H
#define MIDAS_IR_STORE_INST_H 1
#include <midas/IR/Instruction.h>

namespace midas
{
    class Builder;
    class BasicBlock;
    class StoreInst : public Instruction
    {
    friend class Builder;
    public:
        Value* getPointer() const;
        Value* getValue() const;

        void print(std::stringstream& stream) const override;
        std::string ident() const override;
    private:
        StoreInst(BasicBlock* parent, Value* ptr, Value* value);

        Value* m_Ptr;
        Value* m_Value;
    };
}

#endif // MIDAS_IR_LOAD_INST_H