// Copyright 2023 solar-mist

/*
 * Globals are values that do not belong to a specific
 * scope e.g. a function definition
*/

#ifndef MIDAS_IR_GLOBAL_H
#define MIDAS_IR_GLOBAL_H 1
#include <midas/IR/Value.h>

namespace midas
{
    class Global : public Value
    {
    public:
        Global(Module& mod) : Value(mod) {}
    };
}

#endif // MIDAS_IR_GLOBAL_H