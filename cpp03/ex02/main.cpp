/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:11 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/09 11:37:11 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap A("A");
	FragTrap B("B");
	FragTrap C;
	
	C = A; 
	A.attack("X");
	A.highFivesGuys();
	B.attack("Z");
	B.highFivesGuys();
	C.attack("Y");
	C.highFivesGuys();
}