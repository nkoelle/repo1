#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter")
{}

Polymorph::Polymorph(std::string spellname): ASpell(spellname, "turned into a critter")
{}

Polymorph::~Polymorph(){}

Polymorph::Polymorph(const Polymorph& copy)
{
    *this = copy;
}

Polymorph*     Polymorph::clone() const
{
    return new Polymorph(*this);
}