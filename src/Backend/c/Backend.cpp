// Copyright 2023 solar-mist


#include <Backend/c/Backend.h>
#include <Backend/c/Function.h>
#include <midas/IR/Function.h>

namespace midas
{
    CBackend::CBackend()
    {
    }

    void CBackend::compile(Module& mod)
    {
        for(Global* global : mod.getGlobals())
        {
            if(dynamic_cast<Function*>(global))
                backend::compileFunction(m_Buffer, dynamic_cast<Function*>(global));
        }
    }

    void CBackend::print(std::ostream& stream)
    {
        stream << m_Buffer.view();
    }
}