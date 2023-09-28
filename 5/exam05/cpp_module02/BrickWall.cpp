#include "BrickWall.hpp"

BrickWall::BrickWall():ATarget("Inconspicuous Red-brick Wall")
{}

BrickWall::~BrickWall(){}

BrickWall::BrickWall(const BrickWall& copy)
{
    *this = copy;
}

BrickWall&    BrickWall::operator=(const BrickWall& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

const std::string&  BrickWall::getType() const
{
    return(this->type_);
}
BrickWall*  BrickWall::clone() const
{
    return new BrickWall(*this);
}