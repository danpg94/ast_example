#ifndef __ARITHMETICEXPRESSION_H
#define __ARITHMETICEXPRESSION_H

#include "base.h"

class ArithmeticExpressionConstant : public ArithmeticExpression
{
    private:
        int value;
    public:
        ArithmeticExpressionConstant(int value) : ArithmeticExpression()
        {
            this->value = value;
        }
        ~ArithmeticExpressionConstant()
        {
        }
        int Evaluate() override
        {
            return value;
        }
};

BINARYOP(ArithmeticExpressionPlus, ArithmeticExpression, ArithmeticExpression, int, +)
BINARYOP(ArithmeticExpressionMult, ArithmeticExpression, ArithmeticExpression, int, *)
BINARYOP(ArithmeticExpressionMinus, ArithmeticExpression, ArithmeticExpression, int, -)
BINARYOP(ArithmeticExpressionDiv, ArithmeticExpression, ArithmeticExpression, int, /)
BINARYOP(ArithmeticExpressionMod, ArithmeticExpression, ArithmeticExpression, int, %)

UNARYOP(ArithmeticExpressionNeg, ArithmeticExpression, ArithmeticExpression, int, -)

#endif