#include "ATarget.hpp"


ATarget::ATarget(){}

ATarget::ATarget(const std::string& type):type_(type)
{}

ATarget::~ATarget()
{}

ATarget::ATarget(const ATarget& copy)
{
    type_ = copy.type_;
}

ATarget&    ATarget::operator=(const ATarget& origin)
{
    if (this != &origin)
        type_ = origin.type_;
    return (*this);
}

const std::string&  ATarget::getType() const
{
    return(this->type_);
}

void ATarget::getHitBySpell(ASpell const& spell) const
{
    std::cout << type_ << " has been " << spell.getEffects() << "!" << std::endl;
}