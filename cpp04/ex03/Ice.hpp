/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:13:16 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/14 18:26:46 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		Ice* clone() const;
		void use(ICharacter& target);
		~Ice();
};
#endif