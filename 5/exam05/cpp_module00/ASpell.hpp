#pragma once

#include <iostream>

class ATarget;

class ASpell
{
    protected:
    ASpell();
    std::string name_;
    std::string effects_;

    public:
        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell();
        ASpell(const ASpell& copy);
        
        ASpell&         operator=(const ASpell& copy);

        const std::string&    getName() const;
        const std::string&    getEffects() const;

        virtual ASpell* clone() const = 0;
        //void            launch(const ATarget& target);


};