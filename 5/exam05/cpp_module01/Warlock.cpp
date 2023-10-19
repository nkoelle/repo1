#include "Warlock.hpp"


Warlock::Warlock(){}

Warlock::Warlock(const std::string& name,const std::string& title):name_(name),title_(title)
{
    std::cout << name_ << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell*>::iterator it;
    for (it = spellbook_.begin(); it != spellbook_.end(); it++)
    {
        delete  it->second;
        spellbook_.erase(it);
    }
    spellbook_.clear();
    std::cout << name_ << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& copy)
{
    name_= copy.name_;
    title_ = copy.title_;
}

Warlock&    Warlock::operator=(const Warlock& origin)
{
    if (this != &origin)
    {
        name_ = origin.name_;
        title_ = origin.title_;
    }
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

void    Warlock::learnSpell(ASpell* spell)
{
    if (spell)
    {
        if (spellbook_.find(spell->getName()) == spellbook_.end())
            spellbook_.insert(std::make_pair(spell->getName(),spell->clone()));
        else
            return;
    }
}

void    Warlock::forgetSpell(std::string spellname)
{
    if (spellbook_.find(spellname) != spellbook_.end())
    {
        delete spellbook_.find(spellname)->second;
        spellbook_.erase(spellname);
    }
    else
        return;
}

void    Warlock::launchSpell(std::string spellname,ATarget const& targ)
{
    if (spellbook_.find(spellname) != spellbook_.end())
        spellbook_[spellname]->launch(targ);
    else
        return;
}
