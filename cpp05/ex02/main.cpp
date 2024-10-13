/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:18 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 18:16:54 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat br1("br1", 1);
		PresidentialPardonForm pp("Target_1");
		pp.besigned(br1);
		br1.executeForm(pp);


		Bureaucrat br2("br2", 1);
		RobotomyRequestForm rr("Target_2");
		rr.besigned(br2);
		br2.executeForm(rr);

		Bureaucrat br3("br3", 1);
		ShrubberyCreationForm sc("Target_3");
		sc.besigned(br3);
		br3.executeForm(sc);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}