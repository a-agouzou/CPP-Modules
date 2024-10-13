/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:02:52 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 15:31:37 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	name = _name;
	wp = NULL;
}

void HumanB::setWeapon(Weapon &_wp)
{
	wp = &_wp;
}

void HumanB::attack(void)
{
	if(!wp)
		std::cout << name << " can't attack "<< std::endl;
	else
		std::cout << name << " attacks with their " << wp->getType() << std::endl;
}