#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    private:
        
    public:
        Polymorph();
        Polymorph(std::string spellname);
        ~Polymorph();
        Polymorph(const Polymorph& copy);

        std::string&     getType() const;

        Polymorph*       clone() const;
        void             getHitBySpell(const ASpell& spell);

};