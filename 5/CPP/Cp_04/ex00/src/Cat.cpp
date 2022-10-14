/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:11:40 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/14 14:09:43 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string type)
{
    settype(type);
    std::cout << "Cat init constructor called." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}