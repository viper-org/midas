#include "Backend/c/Backend.h"
#include "midas/Backend.h"
#include <midas/Module.h>
#include <midas/IR/Builder.h>
#include <midas/IR/Function.h>
#include <midas/IR/BasicBlock.h>
#include <iostream>

int main()
{
    midas::Module mod("test.tst");
    midas::Function* func = midas::Function::Create(mod, "main", midas::Function::LinkageType::External);

    midas::BasicBlock* bb = midas::BasicBlock::Create("entry", func);

    midas::Builder builder;
    builder.setInsertPoint(bb);
    midas::ConstantInt* val = builder.CreateConstantInt(22);
    builder.CreateRet(val);

    midas::Backend* backend = new midas::CBackend;
    backend->compile(mod);
    backend->print(std::cout);
    std::cout << "\n\n\n";
    mod.print(std::cout);
}