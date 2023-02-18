#ifndef __STATEMENT_H
#define __STATEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include "base.h"

class StatementBlock : public Statement
{
    private:
        std::vector<Statement*> statements;
    public:
        StatementBlock(std::vector<Statement*>& statements)
        {
            this->statements = statements;
        }
        ~StatementBlock()
        {
            for (Statement* statement : statements)
                delete statement;
            statements.clear();
        }
        void Execute() override
        {
            for(Statement* statement : statements)
            {
                statement->Execute();
            }
        }
};

class StatementAssign : public Statement
{
    private:
        LocationValue* lvalue;
        ArithmeticExpression* expression;
    public:
        StatementAssign(LocationValue* lvalue, ArithmeticExpression* expression)
        {
            this->lvalue = lvalue;
            this->expression = expression;
        }
        ~StatementAssign()
        {
            delete lvalue;
            delete expression;
        }
        void Execute() override
        {
            int temp = expression->Evaluate();
        }
};




class StatementWrite : public Statement
{
    private:
        std::string text;
    public:
        StatementWrite(std::string text)
        {
            this->text = text;
        }
        ~StatementWrite()
        {
        }
        void Execute() override
        {
            std::cout << text;
        }
};



class StatementWriteInt : public Statement
{
    private:
        ArithmeticExpression* expression;
    public:
        StatementWriteInt(ArithmeticExpression* expression)
        {
            this->expression = expression;
        }
        ~StatementWriteInt()
        {
            delete expression;
        }
        void Execute() override
        {
            std::cout << ( expression->Evaluate() );
        }
};


class StatementReadInt : public Statement
{
    private:
        LocationValue* lvalue;
    public:
        StatementReadInt(LocationValue* lvalue)
        {
            this->lvalue = lvalue;
        }
        ~StatementReadInt()
        {
            delete lvalue;
        }
        void Execute() override
        {
            int temp;
            std::cin >> temp;
            lvalue->Set(temp);
        }
};

class StatementWhile : public Statement
{
    private:
        BooleanExpression* condition;
        Statement* statement;
    public:
        StatementWhile(BooleanExpression* condition, Statement* statement)
        {
            this->condition = condition;
            this->statement = statement;
        }
        ~StatementWhile()
        {
            delete condition;
            delete statement;
        }
        void Execute() override
        {
            while( condition->Evaluate() )
            {
                statement->Execute();
            }
        }
};

class StatementIfThenElse : public Statement
{
    private:
        BooleanExpression* condition;
        Statement* thencase;
        Statement* elsecase;
    public:
        StatementIfThenElse(BooleanExpression* condition, Statement* thencase, Statement* elsecase)
        {
            this->condition = condition;
            this->thencase = thencase;
            this->elsecase = elsecase;
        }
        ~StatementIfThenElse()
        {
            delete condition;
            delete thencase;
            delete elsecase;
        }
        void Execute() override
        {
            if (condition->Evaluate())
                if (thencase)
                    thencase->Execute();
            else
                if (elsecase)
                    elsecase->Execute();

        }
};

#endif