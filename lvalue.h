#ifndef __L_VALUE_H
#define __L_VALUE_H

#include "base.h"
#include <string>

class LocationValueVariable : public LocationValue
{
    private:
        std::string name;
    public:
        LocationValueVariable(const std::string& name) : LocationValue()
        {
            this->name = name;
        }
        virtual ~LocationValueVariable()
        {

        }
        void Set(int value) override
        {
            // ...
        }
        int Evaluate() override
        {
            return 0;
            // ...
        }
};

#endif