/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:40:53 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/01 15:17:46 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* elem;
		unsigned int lenght;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		unsigned int size() const;
		~Array();
};

template <typename T>
Array<T>::Array()
{
	elem = NULL;
	lenght = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	elem = new T[n];
	lenght = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	elem = new T[lenght];
	lenght = other.lenght;
	for(unsigned int i = 0; i < lenght; i++)
		elem[i] = other.elem[i];
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if(this != &other)
	{
		delete[] elem;
		elem = new T[lenght];
		lenght = other.lenght;
		for(unsigned int i = 0; i < lenght; i++)
			elem[i] = other.elem[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index > lenght)
		throw(std::runtime_error("index out of bounds"));
	return(elem[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (lenght);
}


template <typename T>
Array<T>::~Array()
{
	delete[] elem;
}

#endif