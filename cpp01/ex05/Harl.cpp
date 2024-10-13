/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:14:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 15:48:11 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

int get_index(std::string *tab, std::string level)
{
	for(int i= 0 ; i < 4 ; i++)
	{
		if(tab[i] == level)
			return i;
	}
	return -1;
}

void Harl::complain(std::string level)
{
	int index;
	
	void (Harl::*ptr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; 
	std::string tab[4] = {"DEBUG","INFO", "WARNING", "ERROR"};
	
	if((index = get_index(tab, level)) != -1)
	{
		(this->*ptr[index])();
		return ;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}