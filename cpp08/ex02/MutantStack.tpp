/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:30:44 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/05 16:05:38 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename _Tp, class _Container>
MutantStack<_Tp, _Container>::MutantStack() 
{
    
}

template <typename _Tp, class _Container>
typename MutantStack<_Tp, _Container>::iterator MutantStack<_Tp, _Container>::begin() 
{
    return this->c.begin();
}

template <typename _Tp, class _Container>
typename MutantStack<_Tp, _Container>::iterator MutantStack<_Tp, _Container>::end()
{
    return this->c.end();
}

template <typename _Tp, class _Container>
MutantStack<_Tp, _Container>::MutantStack(const MutantStack& other)
{
	*this = other;
}

template <typename _Tp, class _Container>
MutantStack<_Tp, _Container>& MutantStack<_Tp, _Container>::operator=(const MutantStack& other)
{
	if(this != &other)
	{
		this->c.clear();
		this->c = other.c;
	}
	return *this;
}

template <typename _Tp, class _Container>
MutantStack<_Tp, _Container>::~MutantStack()
{
    
}
