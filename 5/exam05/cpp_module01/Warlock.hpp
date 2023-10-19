#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

class Warlock
{
    private:

    std::string name_;
    std::string title_;
    Warlock(const Warlock& copy);
    Warlock();
    std::map<std::string, ASpell*>  spellbook_;
    public:

    Warlock(const std::string& name,const std::string& title);
    ~Warlock();

    Warlock&  operator=(const Warlock& origin);

    const std::string&  getName() const;
    const std::string&  getTitle() const;

    void    setTitle(const std::string& Warlock);
    void    introduce() const;


    void    learnSpell(ASpell* spell);
    void    forgetSpell(std::string spellname);
    void    launchSpell(std::string spellname,ATarget const& targ);
};