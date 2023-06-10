// Copyright 2023 solar-mist

/*
 * ConstantInts are integer literals
*/

#ifndef MIDAS_IR_CONSTANT_INT_H
#define MIDAS_IR_CONSTANT_INT_H 1
#include <midas/IR/Constant.h>
#include <cstdint>

namespace midas
{
    class Builder;
    class BasicBlock;
    class ConstantInt : public Constant
    {
    friend class Builder;
    public:
        uint64_t getValue();

        void print(std::stringstream& stream) const override;
        std::string ident() const override;
    private:
        ConstantInt(BasicBlock* parent, uint64_t value);

        uint64_t m_Value;
    };
}

#endif // MIDAS_IR_CONSTANT_H