#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(std::string type):type_(type)
{}

ATarget::~ATarget(){}

ATarget::ATarget(const ATarget& copy)
{
    *this = copy;
}

ATarget&    ATarget::operator=(const ATarget& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

const std::string&  ATarget::getType() const
{
    return(this->type_);
}

void    ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
