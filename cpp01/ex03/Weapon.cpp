/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:03:10 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/26 11:33:18 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(std::string _type)
{
	type = _type;
}
Weapon::Weapon(std::string _type)
{
	type = _type;
}