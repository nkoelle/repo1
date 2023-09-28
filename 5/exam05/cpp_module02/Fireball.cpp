#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp")
{}

Fireball::~Fireball(){}

Fireball::Fireball(const Fireball& copy): ASpell("Fireball", "burnt to a crisp")
{
    *this = copy;
}

Fireball*     Fireball::clone() const
{
    return new Fireball(*this);
}
