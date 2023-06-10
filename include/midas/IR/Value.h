// Copyright 2023 solar-mist

/*
 * A value is the base class for every statement or
 * expression in MIDAS
*/

#ifndef MIDAS_IR_VALUE_H
#define MIDAS_IR_VALUE_H 1
#include <sstream>

namespace midas
{
    class Module;

    class Value
    {
    public:
        Value(Module& mod) : mod(mod) {}
        virtual ~Value() {}

        virtual void print(std::stringstream& stream) const = 0;
    protected:
        Module& mod;
    };
}

#endif // MIDAS_IR_VALUE_H