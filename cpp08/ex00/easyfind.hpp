/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:32 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/04 20:31:51 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
int easyfind(T &arg, int n)
{
	typename T::iterator it;
	it = std::find(arg.begin(), arg.end(), n);
	if(it != arg.end())
		return *it;
	else
		throw(std::runtime_error("Number not found"));
}

#endif