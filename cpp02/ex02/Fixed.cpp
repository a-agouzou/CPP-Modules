/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:00:58 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/02 17:31:06 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
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
	*this = copy;
}

int Fixed::getRawBits(void) const
{
	return fixed;
}

void Fixed::setRawBits(const int raw)
{
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
	if(this != &other)
		fixed = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other)
{
	return (fixed > other.fixed);
}

bool Fixed::operator<(const Fixed& other)
{
	return (fixed < other.fixed);
}

bool Fixed::operator>=(const Fixed& other)
{
	return (fixed >= other.fixed);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (fixed <= other.fixed);
}

bool Fixed::operator==(const Fixed& other)
{
	return (fixed == other.fixed);
}

bool Fixed::operator!=(const Fixed& other)
{
	return (fixed != other.fixed);
}

Fixed Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed& Fixed::operator++()
{
	fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixed++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixed--;
	return (temp);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return((first.fixed < second.fixed) ? first : second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return((first.fixed < second.fixed) ? first : second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return((first.fixed > second.fixed) ? first : second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return((first.fixed > second.fixed) ? first : second);
}

Fixed::~Fixed(void)
{
	
}