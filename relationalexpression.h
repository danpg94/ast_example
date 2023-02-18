#ifndef __RELATIONALEXPRESSION_H
#define __RELATIONALEXPRESSION_H

#include "base.h"

BINARYOP(RelationalExpressionEqual, RelationalExpression, ArithmeticExpression, bool, == )
BINARYOP(RelationalExpressionUnequal, RelationalExpression, ArithmeticExpression, bool, != )
BINARYOP(RelationalExpressionLessThan, RelationalExpression, ArithmeticExpression, bool, < )
BINARYOP(RelationalExpressiongGreaterThan, RelationalExpression, ArithmeticExpression, bool, > )
BINARYOP(RelationalExpressionLessOrEqual, RelationalExpression, ArithmeticExpression, bool, <= )
BINARYOP(RelationalExpressiongGreaterOrEqual, RelationalExpression, ArithmeticExpression, bool, >= )

#endif