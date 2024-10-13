/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:11:07 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/05 21:22:12 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
	private:
		std::vector<int>vec;
		unsigned int capacity;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		int shortestSpan(void);
		int longestSpan(void);
		void addNumber(int num);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		~Span();
};

#endif