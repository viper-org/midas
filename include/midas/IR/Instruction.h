// Copyright 2023 solar-mist

/*
 * An instruction is the base class for everything in
 * BasicBlocks in MIDAS, e.g. Returns or Loads
*/

#ifndef MIDAS_IR_INSTRUCTION_H
#define MIDAS_IR_INSTRUCTION_H 1
#include <midas/IR/Value.h>

namespace midas
{
    class Instruction : public Value
    {
    public:
        Instruction(Module& mod) : Value(mod) {}
    };
}

#endif // MIDAS_IR_INSTRUCTION_H