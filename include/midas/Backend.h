// Copyright 2023 solar-mist

/*
 * A backend is an abstract interface to compile MIDAS
 * IR to a specific target, e.g. x86_64 or C
*/

#ifndef MIDAS_BACKEND_H
#define MIDAS_BACKEND_H 1
#include <midas/Module.h>

namespace midas
{
    class Backend
    {
    public:
        virtual ~Backend() {}

        virtual void compile(Module& mod) = 0;
        virtual void print(std::ostream& stream) = 0;
    };
}

#endif // MIDAS_BACKEND_H