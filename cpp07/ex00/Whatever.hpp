/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:58:16 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/02 11:49:04 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &arg1, T &arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template <typename T>
T min(T par1, T &par2)
{
	return (par1 < par2 ? par1 : par2);
}

template <typename T>
T max(T par1, T &par2)
{
	return (par1 > par2 ? par1 : par2);
}
#endif