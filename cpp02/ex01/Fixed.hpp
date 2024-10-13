/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:01:01 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/02 17:21:07 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed;
		const static int fraction = 8;
	public:
		Fixed();
		Fixed(const int integer_num);
		Fixed(const float floating_num);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();	
};
std::ostream& operator<< (std::ostream &out, const Fixed& obj);
#endif