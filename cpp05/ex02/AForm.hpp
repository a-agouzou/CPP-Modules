/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:35:59 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 20:15:10 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;
	public:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string get_name() const;
		bool get_is_signed() const;
		int get_grade_to_sign() const;
		int get_grade_to_exec() const;
		void besigned(Bureaucrat& obj);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class IsNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif