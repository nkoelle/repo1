#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{
    protected:


    public:

    Dummy();
    ~Dummy();

    virtual Dummy*     clone() const;

};