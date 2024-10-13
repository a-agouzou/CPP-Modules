/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/19 14:03:01 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <sys/time.h>
class PmergeMe
{
	private:
		std::vector<int> main_vec;
		std::vector<std::pair<int,int> > pair_vec;
		std::deque<int> main_deque;
		std::deque<std::pair<int,int> > pair_deque;
		int struggler;
		double deque_time;
		double vector_time;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void mergeme_vec(int ac, char *av[]);
		void display_vec();
		void mergeme_deque(int ac, char *av[]);
		void display_deque();
		double getVector_time()const;
		double getDeque_time()const;
};