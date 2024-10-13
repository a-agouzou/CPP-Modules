/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:06:22 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/08 14:18:03 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	hit_points = 100;
	energy_points = 50;
	damage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	hit_points = 100;
	energy_points = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

void ScavTrap::attack(const std::string target)
{
		if(energy_points && hit_points)
	{
		std::cout << "ScavTrap " <<name<< " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ScavTrap " << name<< "can't attack. Already Dead!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if(hit_points)
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "Couldn't set ScavTrap" << name << " To Gate keeper mode. Already Dead!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if(this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.hit_points;
		damage = other.damage;
	}
	return *this;	
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
