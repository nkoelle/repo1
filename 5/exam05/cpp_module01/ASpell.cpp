#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(const std::string& name,const std::string& effects):name_(name),effects_(effects)
{}

ASpell::~ASpell(){}

ASpell::ASpell(const ASpell& copy)
{
    *this = copy;
}

ASpell&    ASpell::operator=(const ASpell& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

const std::string&  ASpell::getName() const
{
    return(this->name_);
}

const std::string&  ASpell::getEffects() const
{
    return(this->effects_);
}

void    ASpell::launch(const ATarget& target)
{
    target.getHitBySpell((*this));
}