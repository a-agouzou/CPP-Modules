/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:16:52 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 17:48:06 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("defaut")
{
	grade = 150;	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if(this->grade <= 0)
		throw(Bureaucrat::GradeTooHighException());
	else if(this->grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	if(this != &other)
		this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
	{
		const_cast<std::string &>(this->name) = other.get_name();
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}

const std::string Bureaucrat::get_name() const
{
	return this->name;
}

int Bureaucrat::get_grade() const
{
	return this->grade;
}

void Bureaucrat::increment_grade()
{
	this->grade--;
	if(this->grade <= 0)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrement_grade()
{
	this->grade++;
	if(this->grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.get_name() << ", bureaucrat grade " << obj.get_grade();
	return out;	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade is too low");
}

void Bureaucrat:: signForm(Form& obj)
{
	try
	{
		obj.besigned(*this);
		std::cout << this->get_name() << " signed " << obj.get_name() << std::endl;
	}	
	catch(const std::exception& e)
	{
		std::cout << this->get_name() << " couldn’t sign " << obj.get_name() << " because " << e.what() << std::endl;
	}
}