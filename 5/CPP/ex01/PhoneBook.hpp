/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:04:22 by nkolle            #+#    #+#             */
/*   Updated: 2022/09/21 18:07:51 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_Class_Hpp
# define PhoneBook_Class_Hpp
#include <iostream>
#include "Contact.hpp"
#include <string>

// Phonebook =  array[7] oldest replaced by newest if 9th contact added
// Contact 
// private and public class

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void	enter_cmd();
		void	addafuckingcontact();
	private:
		//int		index;
		Contact	contacts[3];
		unsigned int next;
		//int		counter;
};

#endif
