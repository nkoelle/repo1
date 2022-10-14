/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:27:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 16:08:19 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
   std::cout << "ScavTrap Default construcor called" << std::endl; 
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name)
{
    std::cout << "ScavTrap init construcor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
   std::cout << "ScavTrap destructor called" << std::endl; 
}

void    ScavTrap::guardGate()
{
    std::cout << getname() << " is now in Gatekeeper mode!" << std::endl;
}