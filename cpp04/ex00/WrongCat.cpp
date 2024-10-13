/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:32:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/10 11:44:19 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if(this != &other)
		type  = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound: Meow!" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}