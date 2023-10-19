#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell
{
    protected:


    public:

    Fwoosh();
    ~Fwoosh();

    virtual Fwoosh*     clone() const;

};