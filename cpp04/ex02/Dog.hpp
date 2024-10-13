/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:43 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/18 12:15:43 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	private:
		Brain *br;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const;
		~Dog();
};

#endif