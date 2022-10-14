/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:11:52 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/14 14:09:38 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string type)
{
    settype(type);
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called." << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}