/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:14:00 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/18 12:19:43 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "idea";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)	
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{	
	std::cout << "Brain destructor called" << std::endl;
}