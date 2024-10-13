/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:11 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/08 18:49:00 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("A");
	ClapTrap B("B");
	ClapTrap C;
	
	C = A; 
	A.attack("X");
	B.attack("Z");
	A.takeDamage(1);
	A.beRepaired(1);
	C.takeDamage(1);
	C.attack("Y");
	C.beRepaired(1);
}