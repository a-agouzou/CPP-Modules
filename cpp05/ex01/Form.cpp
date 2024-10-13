/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:35:56 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 17:49:55 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), grade_to_sign(1), grade_to_exec(1)
{
	is_signed = false;
}

Form::Form(std::string name, int to_sign, int to_exec) : name(name), grade_to_sign(to_sign), grade_to_exec(to_exec)
{
	is_signed = false;
	if(this->grade_to_exec <= 0 || grade_to_sign <= 0)
		throw(Form::GradeTooHighException());
	else if (this->grade_to_exec > 150 || grade_to_sign > 150)
		throw(Form::GradeTooLowException());
}
Form::Form(const Form& other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_exec(other.grade_to_exec)
{
	this->is_signed = other.is_signed;
}

Form& Form::operator=(const Form& other)
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

Form::~Form()
{
	
}

std::string Form::get_name() const
{
	return (this->name);
}

bool Form::get_is_signed() const
{
	return is_signed;
}

int Form::get_grade_to_sign() const
{
	return this->grade_to_sign;
}

int Form::get_grade_to_exec() const
{
	return this->grade_to_exec;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << obj.get_name();
	if(obj.get_is_signed())
		out <<", is signed ";
	else
		out <<", is not signed ";
	out << "and need " << obj.get_grade_to_sign() << " (grades) to signed ";
	out << "and " << obj.get_grade_to_exec() << " (grades) to execute";
	return out;
}

void Form::besigned(Bureaucrat& obj)
{
	if(obj.get_grade() <= this->grade_to_sign)
		is_signed = true;
	else
		throw(Form::GradeTooLowException());
}
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade is too Hight");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade is too low");
}