#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:

    std::string type_;
    ATarget();

    public:

    ATarget(const ATarget& copy);
    ATarget(const std::string& type);
    virtual~ATarget();

    ATarget&  operator=(const ATarget& origin);

    const std::string&  getType() const;

    virtual ATarget*     clone() const = 0;

    void getHitBySpell(ASpell const& spell) const;
};