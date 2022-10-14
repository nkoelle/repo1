/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:57:41 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 11:57:41 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name): _Name(Name), _Hit_points(10), 
_Energy_points(10), _Attack_damage(0)
{
    std::cout << "init constructor called" << std::endl;
}
 
ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

// memberfunctions
void    ClapTrap::attack(const std::string& target)
{
    this->_Energy_points--;
    std::cout << _Name << " attacks " << target << ", ";
    std::cout << "causing " << _Attack_damage << " points of damage." 
    << " It's not very effective!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_Hit_points > amount)
        this->_Hit_points = _Hit_points - amount;
    else
        this->_Hit_points = 0;
    std::cout << getname()<< " hurt himself, taking " << amount 
    << " damage points!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    this->_Energy_points--;
    this->_Hit_points = _Hit_points + amount;
    std::cout << _Name << " healed for " << amount <<
    " of Hit points." << std::endl;
}
// getter

std::string ClapTrap::getname() const
{
    return (this->_Name);
}

unsigned int ClapTrap::getad() const
{
    return (this->_Attack_damage);
}

unsigned int ClapTrap::gethp() const
{
    return (this->_Hit_points);
}

unsigned int ClapTrap::getep() const
{
    return (this->_Energy_points);
}

//operators
std::ostream&			operator<<(std::ostream& out, ClapTrap const& CT)
{
    if (CT.gethp() > 1 && CT.getep() > 1)
    {
        out << CT.getname() << " has " << CT.gethp() << " Hitpoints and " <<
        CT.getep() << " Energypoints left." << std::endl;
        return (out);
    }
    
    if (CT.gethp() == 1 && CT.getep() > 1)
    {
        out << CT.getname() << " has " << CT.gethp() << " Hitpoint and " <<
        CT.getep() << " Energypoints left." << std::endl;
        return (out);
    }

    if (CT.gethp() > 1 && CT.getep() == 1)
    {
        out << CT.getname() << " has " << CT.gethp() << " Hitpoints and " <<
        CT.getep() << " Energypoint left." << std::endl;
        return (out);
    }

    if (CT.gethp() == 1 && CT.getep() == 1)
    {
        out << CT.getname() << " has " << CT.gethp() << " Hitpoint and " <<
        CT.getep() << " Energypoint left." << std::endl;
        return (out);
    }
    
    if (CT.gethp()== 0)
    {
        out << CT.getname() << " has no Hitpoints left and died." <<
        std::endl;
        return (out);
    }

    if (CT.getep()== 0)
    {
        out << CT.getname() << " has no Energypoints left and can't do shit." <<
        std::endl;
        return (out);
    }
    return (out);
}