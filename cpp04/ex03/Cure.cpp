/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:13:10 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/14 14:57:37 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}
Cure::Cure(std::string const &type)
{
	this->type = type;
}

Cure::Cure(const Cure& other)
{
	*this = other;
}

Cure& Cure::operator=(const Cure& other)
{
	if(this != &other)
		this->type = other.type;
	return *this;
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<"'s wounds *"<< std::endl;
		
}

Cure::~Cure()
{
}