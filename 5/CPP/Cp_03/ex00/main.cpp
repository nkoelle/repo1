/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:06:22 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 14:51:43 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Clap_Fred");

    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(5);
    std::cout << a;
    a.beRepaired(4);
    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(5);
    std::cout << a;
    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(5);
    std::cout << a;
    
    return (0);
}
