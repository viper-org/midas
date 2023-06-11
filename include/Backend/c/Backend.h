// Copyright 2023 solar-mist

/*
 * A backend that compiles to C code
*/

#ifndef MIDAS_BACKEND_BACKEND_C
#define MIDAS_BACKEND_BACKEND_C 1
#include <midas/Backend.h>

namespace midas
{
    class Function;
    class RetInst;
    class CBackend : public Backend
    {
    public:
        CBackend();

        void compile(Module& mod) override;
        void print(std::ostream& stream) override;
    private:
        std::stringstream m_Buffer;
    };

    namespace backend
    {
        void compileFunction(std::stringstream& buffer, Function* func);
        void compileRet(std::stringstream& buffer, RetInst* ret);
    }
}

#endif // MIDAS_BACKEND_BACKEND_C