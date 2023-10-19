#include "Warlock.hpp"


Warlock::Warlock(){}

Warlock::Warlock(const std::string& name,const std::string& title):name_(name),title_(title)
{
    std::cout << name_ << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name_ << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& copy)
{
    *this = copy;
}

Warlock&    Warlock::operator=(const Warlock& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

void    Warlock::setTitle(const std::string& title)
{
    this->title_ = title;
}

const std::string&  Warlock::getName() const
{
    return(this->name_);
}

const std::string&  Warlock::getTitle() const
{
    return(this->title_);
}

void    Warlock::introduce() const
{
    std::cout << name_ << ": I am " << name_ << ", " << title_ << "!" << std::endl;
}

