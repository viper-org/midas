// Copyright 2023 solar-mist

/*
 * Function declaration or definition
*/

#ifndef MIDAS_IR_FUNCTION_H
#define MIDAS_IR_FUNCTION_H 1
#include <midas/IR/Global.h>
#include <string>

namespace midas
{
    class Function : public Global
    {
    public:
        enum class LinkageType
        {
            External,
        };

        static Function* Create(Module& mod, std::string name, LinkageType linkage);

        void print(std::stringstream& stream) const override;
    private:
        Function(Module& mod, std::string name, LinkageType linkage);

        std::string m_Name;
        LinkageType m_Linkage;
    };
}

#endif // MIDAS_IR_FUNCTION_H