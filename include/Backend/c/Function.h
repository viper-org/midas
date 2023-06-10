// Copyright 2023 solar-mist

/*
 * Compilation for a MIDAS IR function using the C
 * backend
*/

#ifndef MIDAS_BACKEND_BACKEND_C_FUNCTION
#define MIDAS_BACKEND_BACKEND_C_FUNCTION 1
#include <sstream>

namespace midas
{
    class Function;
    namespace backend
    {
        void compileFunction(std::stringstream& buffer, Function* func);
    }
}

#endif // MIDAS_BACKEND_BACKEND_C_FUNCTION