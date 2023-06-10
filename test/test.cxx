#include <midas/Module.h>
#include <midas/IR/Function.h>
#include <iostream>

int main()
{
    midas::Module mod("test.tst");
    midas::Function* func = midas::Function::Create(mod, "hello", midas::Function::LinkageType::External);
    mod.print(std::cout);
}