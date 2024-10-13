/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:41 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 12:26:16 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	br = new Brain();
}

Dog::Dog(const Dog& other) 
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->br = NULL;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if(this != &other)
	{
		type  = other.type;
		if(this->br)
			delete this->br;
		this->br = new Brain(*(other.br));
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound: Bark!" << std::endl;
}

Dog::~Dog()
{
	delete br;
	std::cout << "Dog destructor called" << std::endl;
}