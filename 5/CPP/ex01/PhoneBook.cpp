/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:08:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/09/21 18:57:55 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	std::cout << "pb constructor called" << std::endl;
	next = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "pb deconstructor called" << std::endl;
}

void	PhoneBook::enter_cmd(void)
{
	std::cout << "Enter a command [ADD, SEARCH or EXIT]" << std::endl;
}

void	PhoneBook::addafuckingcontact()
{
	std::cout << "Consider it done, sir!" << std::endl;
	std::cout << "Contact #" << next << std::endl;
	contacts[next].getdata();
	/*
	 * Wir benutzen den Modulo, um den Wert auf 0-7 zu beschraenken.
	 *
	 * Modulo gibt uns den Rest einer Division, erlaubt uns dadurch
	 * aber auch diese Beschraenkung:
	 * 0 / 8 = 0 R 0  -> 0
	 * 1 / 8 = 0 R 1  -> 1
	 * 2 / 8 = 0 R 2  -> 2
	 * ...
	 * 7 / 8 = 0 R 7  -> 7
	 * 8 / 8 = 1 R 0  -> 0     // Hier Ueberlauf, aber korrekter Wert
	 * 9 / 8 = 1 R 1  -> 1
	 * ...
	 */
	next = (next + 1) % 3;
}
