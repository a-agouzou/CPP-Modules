/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:11 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/09 11:37:49 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap A("A");
	ScavTrap B("B");
	ScavTrap C;
	
	C = A; 
	A.attack("X");
	A.guardGate();
	B.attack("Z");
	B.guardGate();
	C.attack("Y");
	C.guardGate();
}