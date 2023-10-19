#include "ASpell.hpp"


ASpell::ASpell()
{}

ASpell::ASpell(const std::string& name,const std::string& effects):name_(name),effects_(effects)
{ }

ASpell::~ASpell()
{}

ASpell::ASpell(const ASpell& copy)
{
    name_ = copy.name_;
    effects_ = copy.effects_;
}

ASpell&    ASpell::operator=(const ASpell& origin)
{
    if (this != &origin)
    {
        name_ = origin.name_;
        effects_ = origin.effects_;
    }
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

void    ASpell::launch(ATarget const& targ) const
{
    targ.getHitBySpell(*this);
}