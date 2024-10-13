/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:11 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/14 15:15:03 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class Rpn
{
	std::stack<int> stk;
	public:
		Rpn();
		Rpn(const Rpn& other);
		Rpn& operator=(const Rpn& other);
		~Rpn();
		bool rpn(std::string str);
};