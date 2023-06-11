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

    midas::BasicBlock* bb = midas::BasicBlock::Create("", func);

    midas::Builder builder;
    builder.setInsertPoint(bb);

    midas::AllocaInst* alloca = builder.CreateAlloca("");

    midas::ConstantInt* val = builder.CreateConstantInt(22);
    builder.CreateStore(alloca, val);

    midas::Value* load = builder.CreateLoad(alloca, "");

    builder.CreateRet(load);

    midas::Backend* backend = new midas::CBackend;
    backend->compile(mod);
    backend->print(std::cout);
    std::cout << "\n\n\n";
    mod.print(std::cout);
}