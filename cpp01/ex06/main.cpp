/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:39:56 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/21 18:36:05 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[])
{
	if(ac != 2)
	{
		std::cout << "invalid arguments" << std::endl; 
		return 1;
		
	}
	std::string level = av[1];
	Harl tmp;

	tmp.complain(level);
	return 0;
	
}