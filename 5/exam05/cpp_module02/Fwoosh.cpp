#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::Fwoosh(std::string spellname): ASpell(spellname, "fwooshed")
{}

Fwoosh::~Fwoosh(){}

Fwoosh::Fwoosh(const Fwoosh& copy)
{
    *this = copy;
}

Fwoosh&    Fwoosh::operator=(const Fwoosh& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

Fwoosh*     Fwoosh::clone() const
{
    return new Fwoosh(*this);
}