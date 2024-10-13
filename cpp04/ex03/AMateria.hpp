/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:01:29 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/17 19:58:45 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria(); 
	std::string const & getType() const; 
	virtual AMateria* clone() const = 0; 
	virtual void use(ICharacter& target);
};

#endif