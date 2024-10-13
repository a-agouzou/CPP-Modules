/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:18 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/28 20:25:10 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat brc("brc",1);
		Form form("form",2,1);
		std::cout << brc << std::endl;
		std::cout << form << std::endl;
		form.besigned(brc);
		std::cout <<form.get_name() <<" is signed : " << form.get_is_signed() << std::endl;
		
		Bureaucrat brc1("brc1",150);
		Form form1("form1",100,1);
		brc1.signForm(form1);	
		std::cout << form1.get_name() << " is signed : " << form1.get_is_signed() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}