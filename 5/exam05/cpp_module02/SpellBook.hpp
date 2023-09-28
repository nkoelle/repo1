#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include "ASpell.hpp"

class ASpell;

class SpellBook
{
    private:
    SpellBook(const SpellBook& copy);

    public:
    std::map<std::string, ASpell*> spellbook_;
    SpellBook();
    ~SpellBook();

    SpellBook&  operator=(const SpellBook& origin);
    
    void        learnSpell(ASpell* spell);
    void        forgetSpell(std::string const& spellname);
    ASpell*     createSpell(std::string const& spell);

};