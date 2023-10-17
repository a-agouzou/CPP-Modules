/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:05:35 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/12 19:20:05 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main(int argc, char *argv[])
{
	int i;
	int	j;
	
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return 0;
	}
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
			std::cout<< (char)toupper((argv[i][j++]));
		i++;
	}
	std::cout << "\n";
}