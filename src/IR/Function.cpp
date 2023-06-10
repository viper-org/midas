// Copyright 2023 solar-mist


#include <midas/IR/Function.h>
#include <midas/Module.h>
#include <format>

namespace midas
{
    Function* Function::Create(Module& mod, std::string name, LinkageType linkage)
    {
        Function* func = new Function(mod, std::move(name), linkage);

        mod.insertGlobal(func);

        return func;
    }

    Module& Function::getModule() const
    {
        return mod;
    }

    int& Function::getInstNo()
    {
        return m_InstNo;
    }

    void Function::insertBasicBlock(BasicBlock* bb)
    {
        m_BasicBlockList.push_back(bb);
    }

    void Function::print(std::stringstream& stream) const
    {
        std::string linkageName;
        switch(m_Linkage)
        {
            case LinkageType::External:
                linkageName = "public";
                break;
        }

        stream << std::format("define {} i32 @{}() {{\n", linkageName, m_Name);

        for(BasicBlock* bb : m_BasicBlockList)
        {
            bb->print(stream);
            stream << "\n";
        }

        stream << "}";
    }

    Function::Function(Module& mod, std::string name, LinkageType linkage)
        :Global(mod), m_Name(std::move(name)), m_Linkage(linkage)
    {
    }
}