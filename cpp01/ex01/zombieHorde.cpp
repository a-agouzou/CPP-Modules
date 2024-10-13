/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:38 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 14:09:42 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	Zombie *zombie  = new (std::nothrow) Zombie[N];
	if(!zombie)
		return (0);
	for(int i = 0; i < N; i++)
		zombie[i].setname(name);
	return (zombie);
}