#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

class ATarget;

class Dummy : public ATarget
{
    private:
        std::string type_;

    public:
        Dummy();
        ~Dummy();
        Dummy(const Dummy& copy);
        
        Dummy&          operator=(const Dummy& copy);

        const std::string&    getType() const;

        Dummy*          clone() const;

};