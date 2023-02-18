#include "base.h"

#include "arithmeticexpression.h"
#include "booleanexpression.h"
#include "lvalue.h"
#include "relationalexpression.h"
#include "statement.h"

int main(int argc, char** argv){
    
    std::vector<Statement*> block;

    block.push_back(new StatementWrite("Hello, World!\n"));
    block.push_back(new StatementWriteInt(
        new ArithmeticExpressionPlus(
            new ArithmeticExpressionConstant(5),
            new ArithmeticExpressionConstant(7)
    )));
    std::cout << "\n";
    block.push_back(new StatementWrite("Goodbye, World!\n"));
    Statement* program = new StatementBlock(block);
    program->Execute();
    delete program;

    return 0;
}