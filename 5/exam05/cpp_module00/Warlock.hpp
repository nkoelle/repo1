#pragma once

#include <iostream>
#include "ASpell.hpp"

class Warlock
{
    private:

    std::string name_;
    std::string title_;
    Warlock(const Warlock& copy);
    Warlock();

    public:

    Warlock(const std::string& name,const std::string& title);
    ~Warlock();

    Warlock&  operator=(const Warlock& origin);

    const std::string&  getName() const;
    const std::string&  getTitle() const;

    void    setTitle(const std::string& Warlock);
    void    introduce() const;

    // void    learnSpell(ASpell *spell);
    // void    forgetSpell(std::string spellname);
    // void    launchSpell(std::string spellname, ATarget& target);

};