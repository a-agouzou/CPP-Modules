/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:26:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 19:15:33 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation",145,137)
{ 
	this->target = "default";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation",145,137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!this->get_is_signed())
		throw(AForm::IsNotSignedException());
	if(this->get_is_signed() && executor.get_grade() <= this->get_grade_to_exec())
		execute_form();
	else
		throw(AForm::GradeTooLowException());
}

void ShrubberyCreationForm::execute_form() const
{
	std::ofstream out(this->target + "_shrubbery");
	if(out.is_open())
	{
		out << TREE;
		out << "\n\n";
		out << TREE;
		out << "\n\n";
		out << TREE;
		out << "\n\n";
	}
	else
		std::cout << "can't create out file" << std::endl;
}
