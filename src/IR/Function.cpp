// Copyright 2023 solar-mist

#include <format>
#include <midas/IR/Function.h>
#include <midas/Module.h>

namespace midas
{
    Function* Function::Create(Module& mod, std::string name, LinkageType linkage)
    {
        Function* func = new Function(mod, std::move(name), linkage);

        mod.insertGlobal(func);

        return func;
    }

    void Function::print(std::stringstream& stream) const
    {
        stream << std::format("define external i32 @{} {{\n\n}}", m_Name);
    }

    Function::Function(Module& mod, std::string name, LinkageType linkage)
        :Global(mod), m_Name(std::move(name)), m_Linkage(linkage)
    {
    }
}