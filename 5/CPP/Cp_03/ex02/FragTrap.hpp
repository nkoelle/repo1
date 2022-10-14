/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:01:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 16:07:16 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define Fragtrap_HPP

#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
   public:
        FragTrap();
        FragTrap(std::string Name);
        ~FragTrap();

        void    highFivesGuys();

};

#endif