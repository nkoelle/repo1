#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

class ATarget;

class Warlock
{
    private:

    std::string name_;
    std::string title_;
    std::map<std::string, ASpell*> spellbook_;
    Warlock();
    Warlock(const Warlock& copy);

    public:

    Warlock(const std::string& name,const std::string& title);
    ~Warlock();

    Warlock&  operator=(const Warlock& origin);

    const std::string&  getName() const;
    const std::string&  getTitle() const;

    void    setTitle(const std::string& Warlock);
    void    introduce() const;

    void    learnSpell(ASpell *spell);
    void    launchSpell(std::string spellname,const ATarget& target);
    void    forgetSpell(std::string spellname);

};