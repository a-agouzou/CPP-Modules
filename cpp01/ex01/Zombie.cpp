/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:42 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 14:35:05 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string _name)
{
	name = _name;
}

Zombie::Zombie()
{
}
Zombie::~Zombie()
{
	std::cout << name <<": Destructor called" << std::endl;
}
Zombie::Zombie(std::string _name)
{
	name = _name;
}