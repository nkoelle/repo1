#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string type_;

    protected:
        ATarget();
        
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget(const ATarget& copy);
        
        ATarget&          operator=(const ATarget& copy);

        const std::string&  getType() const;

        virtual ATarget* clone() const = 0;
        void             getHitBySpell(const ASpell& spell) const;

};