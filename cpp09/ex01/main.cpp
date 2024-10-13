/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:07 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/14 15:12:34 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char*av[])
{
	if(ac == 2)
	{
		Rpn obj;
		if(!obj.rpn(av[1]))
			std::cout << "Error" << std::endl;	
	}
	else
		std::cout << "invalid argument" << std::endl;
	return 0;
}