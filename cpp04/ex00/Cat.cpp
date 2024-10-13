/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:35 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/10 11:21:01 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if(this != &other)
		type  = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound: Meow!" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}