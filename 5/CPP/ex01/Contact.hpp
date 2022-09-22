/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:26:57 by nkolle            #+#    #+#             */
/*   Updated: 2022/09/21 18:23:29 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_Class_H
# define Contact_Class_H

#include <iostream>
#include <string>

// hold the first name, last name, nickname, phone number, darkest secret
// saved contact cant have empty fields


class Contact 
{
	private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	public:

		Contact();
		~Contact();
		void getdata();
		void printdata();
};



#endif
