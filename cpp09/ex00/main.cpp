/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:58:40 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/14 14:51:12 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char *av[])
{
	if(ac == 2)
	{
		std::ifstream data("data.csv");
		std::ifstream input(av[1]);
		if(!data.is_open() || !input.is_open())
		{
			std::cout << "Error: could not open file. (data / input)" << std::endl;
			return 1;
		}
		else if (data.peek() == std::ifstream::traits_type::eof() || input.peek() == std::ifstream::traits_type::eof() )
		{
			std::cout << "Error: file (data / input) is empty" << std::endl;
			return 1;
		}
		BitcoinExchange bitcoin;
		bitcoin.btc(data, input);
	}
	else
		std::cout << "invalid arguments" << std::endl;
	return 0;
}
