/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:11:02 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/05 21:27:35 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		for(unsigned int i = 0; i < 10; i++)
		{
			unsigned int num = rand() % 1000;
			vec.push_back(num);
		}
		Span sp(20);
		sp.addRange(vec.begin(),vec.end());
		sp.addNumber(0);
		sp.addNumber(-1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}
}