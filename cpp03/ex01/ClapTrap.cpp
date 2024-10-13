/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:05 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/09 14:23:24 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name = "default";
	hit_points = 10;
	energy_points = 10;
	damage = 0;
}

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	name = _name;
	hit_points = 10;
	energy_points = 10;
	damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if(this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.hit_points;
		damage = other.damage;
	}
	return *this;
	
}

void ClapTrap::attack(const std::string& target)
{
	if(energy_points && hit_points)
	{
		std::cout << "ClapTrap " <<name<< " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name<< "can't attack. Already Dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hit_points)
	{
		std::cout << "ClapTrap " << name<< " Take damage of " << amount << " points"<< std::endl;
		hit_points -=amount;
		if(hit_points < 0)
			hit_points = 0;
	}
	else
		std::cout << "ClapTrap " << name<< " can't Take Damage. Already Dead!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points && hit_points)
	{
		std::cout << "ClapTrap " <<name << " repair complete. " << amount << " has been added to its hit points" << std::endl;
		energy_points--;
	}
	else
		std::cout << "can't repair " << name << " ClapTrap. Already Dead / No energy" << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}