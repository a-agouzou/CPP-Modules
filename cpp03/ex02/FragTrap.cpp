/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:07:03 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/08 14:20:31 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hit_points = 100;
	energy_points  =100;
	damage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{ 
	std::cout << "FragTrap constructor called" << std::endl;
	hit_points = 100;
	energy_points  =100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap ass called" << std::endl;
	if(this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		damage = other.damage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if(hit_points)
		std::cout << "FragTrap " << name << " says: HIGH FIVE.!" << std::endl;
	else
		std::cout << "FragTrap " <<name << ", is dead>!" << std::endl; 
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}