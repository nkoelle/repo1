#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

class ATarget;

class Dummy : public ATarget
{
    private:

    public:
        Dummy();
        ~Dummy();

        Dummy*          clone() const;

};