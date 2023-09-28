#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    private:

    public:
        Fwoosh();
        Fwoosh(std::string spellname);
        ~Fwoosh();

        std::string&      getType() const;

        Fwoosh*           clone() const;
        void              getHitBySpell(const ASpell& spell);

};