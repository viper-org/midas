// Copyright 2023 solar-mist

/*
 * A module represents a single translation unit(a file)
 * to be compiled using MIDAS
*/

#ifndef MIDAS_MODULE_H
#define MIDAS_MODULE_H 1
#include <midas/IR/Global.h>
#include <string>
#include <vector>

namespace midas
{
    class Module
    {
    public:
        Module(std::string name);
        ~Module();

        std::string_view getName() const;
        const std::vector<Global*>& getGlobals() const;
        
        void insertGlobal(Global* global);

        void print(std::ostream& stream) const;
    private:
        std::string m_Name;
        std::vector<Global*> m_Globals;
    };
}

#endif // MIDAS_MODULE_H