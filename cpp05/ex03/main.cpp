/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:18 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 20:20:48 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Intern Rndm;
		Bureaucrat brc("brc",1);
		AForm *r;

		r = Rndm.makeForm("presidential pardon", "target");
		r->besigned(brc);
		r->execute(brc);
		delete r;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}