/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:02:48 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/26 11:32:33 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_wp) : wp(_wp)
{
	name = _name;
}


void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}