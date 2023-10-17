/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:40:32 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/14 18:37:27 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{  
	private:
		std::string firstname;
		std::string lastname;
		std::string phone;
		std::string nickname;
		std::string secret;
	public:
		void  set_fname(std::string fname);
		void  set_lname(std::string lname);
		void  set_phone(std::string phone_nbr);
		void  set_nickname(std::string nickname);
		void  set_secret(std::string sct);
		std::string  get_fname(void);
		std::string  get_lname(void);
		std::string  get_phone(void);
		std::string  get_nickname(void);
		std::string  get_secret(void);
};


#endif