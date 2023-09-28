#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::SpellBook(const SpellBook& copy)
{
    *this = copy;
}

SpellBook::~SpellBook(){}

SpellBook&  SpellBook::operator=(const SpellBook& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

void        SpellBook::learnSpell(ASpell* spell)
{    
    if (spell)
    {
        if ((spellbook_.find(spell->getName())) == spellbook_.end())
            spellbook_[spell->getName()] = spell->clone();
        else
            return;
    }
}

void        SpellBook::forgetSpell(std::string const& spellname)
{
    for (std::map<std::string, ASpell*>::iterator ite = spellbook_.begin(); ite != spellbook_.end() ; ite++)
    {
        if (ite->first == spellname)
        {
            delete (ite->second);
            spellbook_.erase(ite);
        }
        else 
            continue;
    }
}

ASpell*       SpellBook::createSpell(std::string const& spell)
{
    ASpell *tmp;
    std::map<std::string, ASpell*>::iterator it = spellbook_.find(spell);
    if (it != spellbook_.end())
    {
        tmp = spellbook_[it->first]; //check
        return (tmp);
    }
    else
        return (nullptr);
}
