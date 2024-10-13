/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:54:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 19:15:15 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()  : AForm("Robotomy Request",72,45)
{
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request",72,45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	*this = other;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
		this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!this->get_is_signed())
		throw(AForm::IsNotSignedException());
	if(this->get_is_signed() && executor.get_grade() <= this->get_grade_to_exec())
		execute_form();
	else
		throw(AForm::GradeTooLowException());
}

void RobotomyRequestForm::execute_form() const
{
	std::srand(std::time(0));
	if((std::rand() % 2) == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
		
}