/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:30:04 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 21:01:23 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon",25,5)
{
	this->target = "default";
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon",25,5)
{
	this->target = target;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
		this->target = other.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(!this->get_is_signed())
		throw(AForm::IsNotSignedException());
	if(this->get_is_signed() && executor.get_grade() <= this->get_grade_to_exec())
		execute_form();
	else
		throw(AForm::GradeTooLowException());
}

void PresidentialPardonForm::execute_form() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
