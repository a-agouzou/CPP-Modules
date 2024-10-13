/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:14:10 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/30 12:52:33 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t ret = Serializer::serialize(&data);

	Data *ptr = Serializer::deserialize(ret);
	if(ptr == &data)
		std::cout << "the addresses are equal" <<std::endl;
	else
		std::cout << "the addresses are not equal" <<std::endl;
	return 0;
}