/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:37:34 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/05 21:54:55 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <typename _Tp, class _Container = std::deque <_Tp> >
class MutantStack : public std::stack<_Tp, _Container>
{
    public:
        typedef typename std::deque<_Tp>::iterator iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other); 
        MutantStack&  operator=(const MutantStack& other);
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif