#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    private:

    public:
        Fwoosh();
        Fwoosh(std::string spellname);
        ~Fwoosh();
        Fwoosh(const Fwoosh& copy);
        
        Fwoosh&           operator=(const Fwoosh& copy);

        std::string&      getType() const;

        Fwoosh*           clone() const;
        void              getHitBySpell(const ASpell& spell);

};