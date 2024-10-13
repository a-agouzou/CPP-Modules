/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:18 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 20:25:44 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat tmp("A", 1);
		Bureaucrat tmp1("B", 150);
		std::cout<< tmp.get_name() << " grade is: " << tmp.get_grade() << std::endl;
		std::cout<< tmp1.get_name() << " grade is: " << tmp1.get_grade() << std::endl;
		tmp.decrement_grade();
		tmp1.increment_grade();
		std::cout<< tmp.get_name() << " grade is: " << tmp.get_grade() << std::endl;
		std::cout<< tmp1.get_name() << " grade is: " << tmp1.get_grade() << std::endl;
		tmp.increment_grade();
		tmp1.decrement_grade();
		std::cout<< tmp.get_name() << " grade is: " << tmp.get_grade() << std::endl;
		std::cout<< tmp1.get_name() << " grade is: " << tmp1.get_grade() << std::endl;
		
		std::cout << tmp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}