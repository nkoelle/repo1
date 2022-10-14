/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:57:51 by nkolle            #+#    #+#             */
/*   Updated: 2022/10/11 14:49:05 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  private:
    std::string     _Name;
    unsigned int    _Hit_points;
    unsigned int    _Energy_points;
    unsigned int    _Attack_damage;
    
  public:
    ClapTrap();
    ClapTrap(std::string Name);
    ~ClapTrap();
  
    void         attack(const std::string& target);
    void         takeDamage(unsigned int amount);
    void         beRepaired(unsigned int amount);

    std::string  getname() const;
    unsigned int getad() const;
    unsigned int getep() const;
    unsigned int gethp() const;

    void    setad(unsigned int amount);
    void    setep(unsigned int amount);
    void    sethp(unsigned int amount);

};

std::ostream&			operator<<(std::ostream& out, ClapTrap const& CT);

#endif