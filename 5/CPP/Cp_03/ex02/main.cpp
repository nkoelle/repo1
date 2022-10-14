/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:06:22 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 16:07:07 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap a("Frag_Fred");

    std::cout << a;
    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(50);
    std::cout << a;
    a.beRepaired(40);
    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(50);
    std::cout << a;
    a.attack("Hedgehog");
    std::cout << a;
    a.takeDamage(50);
    a.guardGate();
    std::cout << a;
    a.highFivesGuys();
    
    return (0);
}
