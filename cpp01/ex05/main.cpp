/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:14:23 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/27 16:01:40 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl tmp;

	tmp.complain("DEBUG");
	tmp.complain("INFO");
	tmp.complain("WARNING");
	tmp.complain("ERROR");
	return 0;
}