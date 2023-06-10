// Copyright 2023 solar-mist

/*
 * BasicBlocks represent a label that stores
 * instructions and can be branched to (conditionally)
*/

#ifndef MIDAS_IR_BASIC_BLOCK_H
#define MIDAS_IR_BASIC_BLOCK_H 1
#include <midas/IR/Value.h>
#include <vector>

namespace midas
{
    class Function;
    class Instruction;
    class BasicBlock : public Value
    {
    friend class Function;
    public:
        static BasicBlock* Create(std::string name, Function* parent);

        Function* getParent() const;
        const std::vector<Instruction*>& getInstructions() const;

        void insertInstruction(Instruction* instruction);

        void print(std::stringstream& stream) const override;
        std::string ident() const override;

    private:
        BasicBlock(std::string name, Function* parent);

        std::string m_Name;
        std::vector<Instruction*> m_InstructionList;
        Function* m_Parent;
    };
}

#endif // MIDAS_IR_BASIC_BLOCK_H