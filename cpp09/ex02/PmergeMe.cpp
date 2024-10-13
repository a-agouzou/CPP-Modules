/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:57:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/19 14:21:38 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		main_vec = other.main_vec;
		pair_vec = other.pair_vec;
		main_deque = other.main_deque;
		pair_deque = other.pair_deque;
		struggler = other.struggler;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	
}

void PmergeMe::display_vec()
{
	for(std::vector<int>::const_iterator it = main_vec.begin(); it != main_vec.end(); it++)
		std::cout << *it << " ";
	// std::cout << std::endl;
}

double PmergeMe::getVector_time() const
{
	return (vector_time);
}

double PmergeMe::getDeque_time() const
{
	return (deque_time);
}

static bool isNum(const char *str)
{
	size_t i = 0;
	if(!*str)
		return 0;
	if(str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while(str[i])
	{
		if(!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}


static long long jacob_numbers(int n)
{
	if(n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return(jacob_numbers(n - 1) + 2 * jacob_numbers(n - 2));
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////         std::vector       ///////////////////////////
/////////////////////////////////////////////////////////////////////////////////

static void insert_back_to_main(std::vector<int> &main_vec, std::vector<std::pair<int,int> >& pair_vec)
{
	main_vec.clear();
	main_vec.push_back(pair_vec[0].second);
	main_vec.push_back(pair_vec[0].first);
	for(size_t i = 1; i < pair_vec.size(); i++)
		main_vec.push_back(pair_vec[i].first);
}

static void sort_main(std::vector<int> &main_vec, std::vector<std::pair<int,int> >& pair_vec, int& struggler)
{
	std::vector<long long>jacb_nums;
	for(size_t i = 0; i >= 0; i++)
	{
		long long value = jacob_numbers(i);
		jacb_nums.push_back(value);
		if((unsigned long)value >= (pair_vec.size() + 1))
			break;
	}
	size_t i = 3;
	size_t stop = 1;
	for (; i < jacb_nums.size(); i++)
	{
		size_t start = jacb_nums[i];
		while(start > stop)
		{
			if((start - 1) < pair_vec.size())
			{
				std::vector<int>::iterator it = std::lower_bound(main_vec.begin(), main_vec.end(),pair_vec[start - 1].second);
				main_vec.insert(it, pair_vec[start - 1].second);
			}
			start--;
		}
		stop = jacb_nums[i];
	}
	if(struggler != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(main_vec.begin(), main_vec.end(),struggler);
		main_vec.insert(it, struggler);
	}

}



static void make_pairs(std::vector<int> &main_vec, std::vector<std::pair<int,int> >& pair_vec)
{
	for(size_t i = 0; i < main_vec.size(); i+=2)
	{
		if(main_vec[i] > main_vec[i + 1])
			pair_vec.push_back(std::make_pair(main_vec[i], main_vec[i + 1]));
		else
			pair_vec.push_back(std::make_pair(main_vec[i + 1], main_vec[i]));

	}
    std::sort(pair_vec.begin(), pair_vec.end());
}

void PmergeMe::mergeme_vec(int ac, char *av[])
{
    struct timeval start, end;
	int i  = 1;
	if(ac < 4)
	{
		std::cout << "Error\nUsage: " << av[0] << " at least 3 positive integers" << std::endl;
		exit(0);
	}
	struggler = -1;
	if((ac % 2) == 0)
	{
		if((!isNum(av[ac - 1]) || atoi(av[ac - 1]) < 0))
		{
			std::cout << "Error: " << av[ac - 1] << std::endl;
			exit(1);
		}	
		struggler = atoi(av[ac - 1]);
		ac--;
	}
	while(i < ac)
	{
		if(!isNum(av[i]) || (atoi(av[i]) < 0))
		{
			std::cout << "Error: " << av[i] << std::endl;
			exit(1);
		}
		main_vec.push_back(atoi(av[i]));
		i++;
	}
	std::cout << "Before:  ";
	display_vec();
	if(struggler != -1)
		std::cout << struggler;
	std::cout << std::endl;
	gettimeofday(&start, NULL);
	make_pairs(main_vec, pair_vec);
	insert_back_to_main(main_vec, pair_vec);
	sort_main(main_vec, pair_vec, struggler);
	gettimeofday(&end, NULL);
	vector_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
	
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////         std::deque       ////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void PmergeMe::display_deque()
{
	for(std::deque<int>::const_iterator it = main_deque.begin(); it != main_deque.end(); it++)
		std::cout << *it << " ";
}

static void insert_back_to_main_deque(std::deque<int> &main_deque, std::deque<std::pair<int,int> >& pair_deque)
{
	main_deque.clear();
	 std::deque<std::pair<int,int> >::iterator it = pair_deque.begin();
	main_deque.push_back(it->second);
	main_deque.push_back(it->first);
	it++;
	for(; it != pair_deque.end(); it++)
		main_deque.push_back(it->first);
}

static void make_deque_pairs(std::deque<int> &main_deque, std::deque<std::pair<int,int> >& pair_deque)
{
	for(std::deque<int>::iterator it = main_deque.begin(); it != main_deque.end(); it+=2)
	{
		if(*(it + 1) > *it)
			pair_deque.push_back(std::make_pair(*(it + 1), *it));
		else
			pair_deque.push_back(std::make_pair(*it, *(it + 1)));
	}
    std::sort(pair_deque.begin(), pair_deque.end());
}

static void sort_main_deque(std::deque<int> &main_deque, std::deque<std::pair<int,int> >& pair_deque, int& struggler)
{
	std::vector<long long>jacb_nums;
	for(size_t i = 0; i >= 0; i++)
	{
		long long value = jacob_numbers(i);
		jacb_nums.push_back(value);
		if((unsigned long)value >= (pair_deque.size() + 1))
			break;
	}

	size_t i = 3;
	size_t stop = 1;
	for (; i < jacb_nums.size(); i++)
	{
		size_t start = jacb_nums[i];
		while(start != stop)
		{
			if((start - 1) < pair_deque.size())
			{
				std::deque<int>::iterator it = std::lower_bound(main_deque.begin(), main_deque.end(), pair_deque[start - 1].second);
				main_deque.insert(it, pair_deque[start - 1].second);
			}
			start--;
		}
		stop = jacb_nums[i];
	}
	if(struggler != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(main_deque.begin(), main_deque.end(),struggler);
		main_deque.insert(it,struggler);
	}

}


void PmergeMe::mergeme_deque(int ac, char *av[])
{
    struct timeval start, end;
	struggler = -1;
	int i  = 1;
	if((ac % 2) == 0)
	{
		struggler = atoi(av[ac - 1]);
		ac--;
	}
	while(i < ac)
		main_deque.push_back(atoi(av[i++]));
    gettimeofday(&start, NULL);
	make_deque_pairs(main_deque, pair_deque);
	insert_back_to_main_deque(main_deque, pair_deque);
	sort_main_deque(main_deque, pair_deque, struggler);	
    gettimeofday(&end, NULL);
    deque_time = (((end.tv_sec - start.tv_sec) * 1000.0)) + ((end.tv_usec - start.tv_usec) / 1000.0);
}
