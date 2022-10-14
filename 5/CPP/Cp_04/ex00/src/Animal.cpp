/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:10:59 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/14 14:11:27 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

void    Animal::settype(std::string type)
{
    this->_type = type;
}

std::string    Animal::getType() const
{
    return (this->_type);
}

void    Animal::makeSound() const
{
    std::cout << "silence" << std::endl;
}