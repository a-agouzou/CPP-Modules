/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:44:13 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 14:01:51 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i=0; i < 4; i++)
		skills[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i=0; i < 4; i++)
		skills[i] = NULL;
	*this = other;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for(int i=0; i < 4 ;i++)
		{
			if(this->skills[i])
				delete this->skills[i];
			if(other.skills[i])
				this->skills[i] = other.skills[i]->clone();
			else
				this->skills[i] = NULL;	
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if(!materia)
		return ;
	for(int i=0; i < 4; i++)
	{
		if(skills[i] == NULL)
		{
			skills[i] = materia;
			return ;
		}
	}
	std::cout << "failed to learn [Materia]. reached the limit" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	
	for(int i =0; i < 4; i++)
	{
		if(skills[i] && (skills[i]->getType()) == type)
		{
			return skills[i]->clone();
		}
	}
	std::cout << "Unknown Materia. unable to create" << std::endl;
	return NULL;
}

MateriaSource::~MateriaSource()
{
	for(int i= 0; i < 4; i++)
		delete skills[i];
}