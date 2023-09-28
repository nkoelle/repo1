#pragma once

#include<iostream>
#include<map>
#include<algorithm>
#include"ATarget.hpp"

class ATarget;

class TargetGenerator
{
    private:
        TargetGenerator(const TargetGenerator& copy);
        std::map<std::string, ATarget*> targ_;

    public:

        TargetGenerator();
        ~TargetGenerator();

        TargetGenerator&    operator=(const TargetGenerator& origin);

        void        learnTargetType(ATarget* type);
        void        forgetTargetType(std::string const& target);
        ATarget*    createTarget(std::string const& new_targ);
};