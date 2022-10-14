/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:38:24 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/14 14:11:36 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    
    public:
        Animal();
        ~Animal();
        
        virtual void    makeSound()const;
        std::string     getType()const;
        void            settype(std::string type);
};

#endif