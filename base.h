#ifndef __BASE_H
#define __BASE_H

class Statement
{
    public:
        Statement();
        virtual ~Statement();
        virtual void Execute() = 0;

};

class BooleanExpression
{
    public:
        BooleanExpression();
        virtual ~BooleanExpression();
        virtual bool Evaluate() = 0;
};

class RelationalExpression : public BooleanExpression
{
    public:
        RelationalExpression();
        ~RelationalExpression();
};

class ArithmeticExpression
{
    public:
        ArithmeticExpression();
        virtual ~ArithmeticExpression();
        virtual int Evaluate() = 0;
};

class LocationValue : public ArithmeticExpression
{
    public:
        LocationValue();
        virtual ~LocationValue();
        virtual void Set(int value) = 0;
};

#define BINARYOP(NAME, BASETYPE, CONTENTTYPE, RETURNTYPE, OPERATION) \
    class NAME : public BASETYPE { \
        CONTENTTYPE* l; \
        CONTENTTYPE* r; \
        public: \
            NAME(CONTENTTYPE* l, CONTENTTYPE* r) : BASETYPE(){ \
                this->l = l; \
                this->r = r; \
            } \
            ~NAME(){ \
                delete l; \
                delete r; \
            } \
            RETURNTYPE Evaluate() override{ \
                return l->Evaluate() OPERATION r->Evaluate(); \
            } \
    };

#define UNARYOP(NAME, BASETYPE, CONTENTTYPE, RETURNTYPE, OPERATION) \
    class NAME : public BASETYPE { \
        CONTENTTYPE* x; \
        public: \
            NAME(CONTENTTYPE* x) : BASETYPE(){ \
                this->x = x; \
            } \
            ~NAME(){ \
                delete x; \
            } \
            RETURNTYPE Evaluate() override { \
                return OPERATION ( x->Evaluate() ); \
            } \
    };
#endif