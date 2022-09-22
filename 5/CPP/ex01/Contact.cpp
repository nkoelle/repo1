/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:10:27 by nkolle            #+#    #+#             */
/*   Updated: 2022/09/21 18:10:17 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "contact deconstructor called" << std::endl;
}

void	Contact::getdata()
{
	std::cout << "First name : " << std::endl;
	std::cin >> first_name;
	std::cout << "Last name : " << std::endl;
	std::cin >> last_name;
	std::cout << "Nickname : " << std::endl;
	std::cin >> nickname;
	std::cout << "Number : " << std::endl;
	std::cin >> phone_number;
	std::cout << "Darkest Secret : " << std::endl;
	std::cin >> darkest_secret;
}