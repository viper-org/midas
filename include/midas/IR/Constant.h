// Copyright 2023 solar-mist

/*
 * Constants are literal values such as integers or
 * strings
*/

#ifndef MIDAS_IR_CONSTANT_H
#define MIDAS_IR_CONSTANT_H 1
#include <midas/IR/Value.h>

namespace midas
{
    class Constant : public Value
    {
    public:
        Constant(Module& mod) : Value(mod) {}
    };
}

#endif // MIDAS_IR_CONSTANT_H