// Copyright 2023 solar-mist

#include <midas/Module.h>
#include <sstream>
#include <format>

namespace midas
{
    Module::Module(std::string name)
        :m_Name(std::move(name))
    {
    }

    Module::~Module()
    {
        for(Global* global : m_Globals)
            delete global;
    }


    std::string_view Module::getName() const
    {
        return m_Name;
    }


    void Module::insertGlobal(Global* global)
    {
        m_Globals.push_back(global);
    }


    void Module::print(std::ostream& stream) const
    {
        std::stringstream buffer;

        buffer << std::format("file \"{}\"\n\n", m_Name);

        for(Global* global : m_Globals)
        {
            global->print(buffer);
            buffer << "\n\n";
        }

        stream << buffer.view();
    }
}