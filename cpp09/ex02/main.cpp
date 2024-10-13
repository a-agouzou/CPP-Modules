/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:16 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/19 14:20:36 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

// bool isSorted(const std::vector<int>& vec) {
//     for (std::vector<int>::size_type i = 1; i < vec.size(); ++i) {
//         if (vec[i] < vec[i - 1]) {
//             return false;
//         }
//     }
//     return true;
// }

int main(int ac, char *av[])
{
	PmergeMe merge;
	merge.mergeme_vec(ac, av);
	std::cout << "After :  ";
	merge.mergeme_deque(ac, av);
	merge.display_deque();
	std::cout << std::setprecision(5);
	std::cout <<"\nTime to process a range of " << ac - 1 << " elements with std::vector : " << merge.getVector_time() << " ms" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << merge.getDeque_time() << " ms" << std::endl;
}