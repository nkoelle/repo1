/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:24:19 by nkolle            #+#    #+#             */
/*   Updated: 2022/09/21 18:56:33 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	cmd;	

	pb.enter_cmd();
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			pb.addafuckingcontact();
		else if (cmd == "EXIT")
			break;
		// if (cmd.compare("SEARCH") == 0)
		// 	// suche in ponebook array nach name, print
	}
	return (0);
}
 