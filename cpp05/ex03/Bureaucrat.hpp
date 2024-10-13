/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:16:54 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/23 16:57:52 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		int grade;
		const std::string name;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string get_name() const;
		int get_grade() const;
		void increment_grade();
		void decrement_grade();
		void signForm(AForm& obj);
		void executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
		{
			public:
				 const char* what() const _NOEXCEPT;
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				 const char* what() const _NOEXCEPT;
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
#endif