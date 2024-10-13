/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:16:54 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/24 17:59:51 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
#endif