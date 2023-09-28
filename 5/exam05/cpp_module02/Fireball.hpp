#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
    private:

    public:
        Fireball();
        ~Fireball();
        Fireball(const Fireball& copy);
    

        std::string&      getType() const;

        Fireball*         clone() const;
        void              getHitBySpell(const ASpell& spell);

};