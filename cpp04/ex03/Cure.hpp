/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:13:12 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/14 18:27:33 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		Cure* clone() const;
		void use(ICharacter& target);
		~Cure();
};

#endif