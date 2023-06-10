#include <midas/Module.h>
#include <midas/IR/Builder.h>
#include <midas/IR/Function.h>
#include <midas/IR/BasicBlock.h>
#include <iostream>

int main()
{
    midas::Module mod("test.tst");
    midas::Function* func = midas::Function::Create(mod, "hello", midas::Function::LinkageType::External);

    midas::BasicBlock* bb = midas::BasicBlock::Create("test", func);

    midas::Builder builder;
    builder.setInsertPoint(bb);
    midas::ConstantInt* val = builder.CreateConstantInt(22);
    builder.CreateRet(val);
    mod.print(std::cout);
}