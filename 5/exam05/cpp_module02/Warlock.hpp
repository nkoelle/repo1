#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

class ATarget;

class SpellBook;

class Warlock
{
    private:

    std::string name_;
    std::string title_;
    Warlock();
    Warlock(const Warlock& copy);

    public:
    SpellBook   Spellbook_;

    Warlock(const std::string& name,const std::string& title);
    ~Warlock();

    Warlock&  operator=(const Warlock& origin);

    const std::string&  getName() const;
    const std::string&  getTitle() const;

    void    setTitle(const std::string& Warlock);
    void    introduce() const;

    void            learnSpell(ASpell *spell);
    void            launchSpell(std::string spellname,const ATarget& target);
    void            forgetSpell(std::string spellname);

};