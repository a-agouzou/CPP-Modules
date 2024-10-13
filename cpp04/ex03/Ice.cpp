/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:13:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/14 14:57:56 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}
Ice::Ice(std::string const &type)
{
	this->type = type;
}

Ice::Ice(const Ice& other)
{
	*this = other;
}

Ice& Ice::operator=(const Ice& other)
{
	if(this != &other)
		this->type = other.type;
	return *this;
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}

Ice::~Ice()
{
}