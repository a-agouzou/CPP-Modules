/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:25:08 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/14 18:38:01 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_fname(std::string fname)
{
	this->firstname = fname;
}
void	Contact::set_lname(std::string lname)
{
	this->lastname = lname;
}
void	Contact::set_phone(std::string phone_nbr)
{
	this->phone = phone_nbr;
}
void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}
void	Contact::set_secret(std::string sct)
{
	this->secret = sct;
}

std::string  Contact::get_fname(void)
{
	return(this->firstname);
}

std::string  Contact::get_lname(void)
{
	return(this->lastname);
}

std::string  Contact::get_phone(void)
{
	return(this->phone);
}
std::string  Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string  Contact::get_secret(void)
{
	return (this->secret);
}