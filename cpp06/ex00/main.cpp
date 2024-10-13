/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:20:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 21:20:43 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if(ac != 2)
    {
        std::cout << "invalid arguments" << std::endl;
        return 0;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}