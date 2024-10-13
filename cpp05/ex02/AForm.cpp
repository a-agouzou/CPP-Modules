/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:35:56 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 18:02:05 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), grade_to_sign(10), grade_to_exec(150)
{
	is_signed = false;
}

AForm::AForm(std::string name, int to_sign, int to_exec) : name(name), grade_to_sign(to_sign), grade_to_exec(to_exec)
{
	is_signed = false;
	if(this->grade_to_exec <= 0 || grade_to_sign <= 0)
		throw(AForm::GradeTooHighException());
	else if (this->grade_to_exec > 150 || grade_to_sign > 150)
		throw(AForm::GradeTooLowException());
}
AForm::AForm(const AForm& other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_exec(other.grade_to_exec)
{
	this->is_signed = other.is_signed;
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		const_cast<std::string &>(this->name) = other.get_name();
		const_cast<int &>(this->grade_to_sign) = other.get_grade_to_sign();
		const_cast<int &>(this->grade_to_exec) = other.get_grade_to_exec();
		this->is_signed = other.get_is_signed();
	}
	return *this;
}

AForm::~AForm()
{
	
}

std::string AForm::get_name() const
{
	return (this->name);
}

bool AForm::get_is_signed() const
{
	return is_signed;
}

int AForm::get_grade_to_sign() const
{
	return this->grade_to_sign;
}

int AForm::get_grade_to_exec() const
{
	return this->grade_to_exec;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.get_name();
	if(obj.get_is_signed())
		out <<", is signed ";
	else
		out <<", is not signed ";
	out << "and need " << obj.get_grade_to_sign() << " (grade) to signed ";
	out << "and " << obj.get_grade_to_exec() << " (grade) to execute";
	return out;
}

void AForm::besigned(Bureaucrat& obj)
{
	if(obj.get_grade() <= this->grade_to_sign)
		is_signed = true;
	else
		throw(AForm::GradeTooLowException());
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form Grade is too Hight");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form Grade is too low");
}

const char* AForm::IsNotSignedException::what() const throw()
{
	return ("Form is not signed");
}