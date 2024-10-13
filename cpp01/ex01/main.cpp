/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:34 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 14:15:07 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *z = zombieHorde(N, "foo");
	if(!z)
	{
		std::cout << "Error" << std::endl;		
		return 1;
	}
	for(int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
}