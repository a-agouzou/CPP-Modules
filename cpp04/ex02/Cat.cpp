/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:35 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 12:28:02 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	br = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->br = NULL;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if(this != &other)
	{
		type  = other.type;
		if(this->br)
			delete this->br;
		this->br = new Brain();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound: Meow!" << std::endl;
}
Cat::~Cat()
{
	delete br;
	std::cout << "Cat destructor called" << std::endl;
}