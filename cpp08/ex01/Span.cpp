/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:11:05 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/05 21:26:03 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	capacity = 0;
}

Span::Span(unsigned int N)
{
	capacity = N;
}
void Span::addNumber(int num)
{
	if(vec.size() < capacity)
		vec.push_back(num);
	else
		throw(std::out_of_range("the array is full"));
}

int Span::longestSpan(void)
{
	if(vec.size() >= 2)
	{
		std::sort(vec.begin(), vec.end());
		return (vec.back() - vec.front());
	}
	else
		throw(std::logic_error("vector is empty or has only one element"));
}

int Span::shortestSpan(void)
{
	if(vec.size() >= 2)
	{
		std::sort(vec.begin(), vec.end());
		int min = vec[1] - vec[0];
		unsigned int i = 1;
		for(;i < vec.size();i++)
		{
			if((vec[i] - vec[i - 1]) < min)
				min = (vec[i] - vec[i - 1]);
		}
		return min;
		
	}
	else
		throw(std::logic_error("vector is empty or has only one element"));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	long int range = std::distance(begin,end);
	long int remaining = capacity - vec.size();
	if(remaining >= range)
		vec.insert(vec.end(),begin,end);
	else
		throw(std::logic_error("no enough capacity"));
	// std::cout << "no enough capacity" << std::endl;
}

Span::~Span()
{
}