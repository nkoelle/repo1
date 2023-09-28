#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget
{
    private:
        std::string type_;

    public:
        BrickWall();
        ~BrickWall();
        BrickWall(const BrickWall& copy);
        
        BrickWall&          operator=(const BrickWall& copy);

        const std::string&    getType() const;

        BrickWall*          clone() const;

};