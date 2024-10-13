/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:01:27 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/17 19:38:43 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}
AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
}
AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	// if(this != &other)
	// 	type = other.type;
	return *this;
}
std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << "uses a Materia" << std::endl;
}

AMateria::~AMateria()
{
	
}