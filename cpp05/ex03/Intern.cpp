/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:02:10 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 20:16:12 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	AForm *tmp;
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int index = get_index(forms, form);
	switch (index)
	{
		case 0:
		{
			tmp = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << tmp->get_name() << std::endl;
			return tmp;
		}
		case 1:
		{
			tmp = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << tmp->get_name() << std::endl;
			return tmp;
		}
		case 2:
		{
			tmp = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << tmp->get_name() << std::endl;
			return tmp;
		}
		default:
			throw(Intern::NoFormFoundException());
	}
}

int Intern::get_index(std::string *forms, std::string form)
{
	for(int i = 0 ;i < 3; i++)
	{
		if(forms[i] == form)
			return i;
	}
	return -1;
}

const char * Intern::NoFormFoundException::what() const throw()
{
	return ("Intern No form found");
}

Intern::~Intern()
{
}