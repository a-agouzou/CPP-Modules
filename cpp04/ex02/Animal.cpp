/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:30 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/18 12:20:27 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
}

std::string Animal::getType() const
{
	return (type);
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if(this != &other)
		type  = other.type;
	return *this;
}


Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}