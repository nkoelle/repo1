#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:

    std::string name_;
    std::string effects_;

    public:

    ASpell(const ASpell& copy);
    ASpell();
    ASpell(const std::string& name,const std::string& effects);
    virtual~ASpell();

    ASpell&  operator=(const ASpell& origin);

    const std::string&  getName() const;
    const std::string&  getEffects() const;

    virtual ASpell*     clone() const = 0;

    void    launch(ATarget const & targ) const;
};