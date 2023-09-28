#include "Dummy.hpp"

Dummy::Dummy():ATarget("Target Practice Dummy")
{}

Dummy::~Dummy(){}

Dummy::Dummy(const Dummy& copy)
{
    *this = copy;
}

Dummy&    Dummy::operator=(const Dummy& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

const std::string&  Dummy::getType() const
{
    return(this->type_);
}
Dummy*  Dummy::clone() const
{
    return new Dummy(*this);
}