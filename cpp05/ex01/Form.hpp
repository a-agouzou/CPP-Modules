/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:35:59 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/22 19:41:52 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string get_name() const;
		bool get_is_signed() const;
		int get_grade_to_sign() const;
		int get_grade_to_exec() const;
		void besigned(Bureaucrat& obj);
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
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif