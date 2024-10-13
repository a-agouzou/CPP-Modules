/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:16:51 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 12:18:38 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->name = "default";
	this->index = 0;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	this->index = 0;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}
Character::Character(const Character& other)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		this->name = other.name;
		for(int i=0; i < 4; i++)
		{
			if(this->inventory[i])
				delete inventory[i];
			if(other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character:: equip(AMateria* m)
{
	if(m == NULL)
		return ;
	int i = 0;
	while(i < 4)
	{
		if(inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;		
		}
		i++;
	}
	if (i >= 4){
		delete m;
		std::cout << "Maximum Materia limit reached. Unable to equip" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if(index == 100)
	{
		std::cout << "couldn't uniquip: you reached the limit" << std::endl;
		return ;
	}
	for(int i=0; i < 4; i++)
	{
		if(i == idx)
		{
			garbage[index] = inventory[i];
			inventory[i] = NULL;
			index++;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if(idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "invalid idx" << std::endl;
}

Character::~Character()
{
	for(int i= 0; i < index; i++)
		delete garbage[i];
	for(int i=0; i < 4; i++)
		delete inventory[i];
}