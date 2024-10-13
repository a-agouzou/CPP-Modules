/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:00:58 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/02 17:20:44 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed = 0;
}
Fixed::Fixed(const int integer_num)
{
	fixed = integer_num << fraction;
}

Fixed::Fixed(const float floating_num)
{
	fixed = roundf(floating_num * 256);
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed = raw;
}

float Fixed::toFloat(void) const
{
	return((1.0f * fixed) / (1.0f * (1 << fraction)));
}

int Fixed::toInt(void) const
{
	return (fixed >> fraction);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		fixed = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}