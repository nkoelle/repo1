/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:22:57 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 16:07:51 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout <<  "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string Name): ScavTrap(Name)
{
    FragTrap::setad(30);
    FragTrap::setep(100);
    FragTrap::sethp(100);
    std::cout <<  "FragTrap init constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout <<  "FragTrap destructor called." << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "Hit the FIVE buddy." << std::endl;
}