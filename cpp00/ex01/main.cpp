/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:03:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/18 21:20:28 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int isnum(std::string input)
{
	for(std::size_t i = 0; i < input.length(); i++)
	{
		if(!std::isdigit(input[i]))
			return 0;
	}
	return 1;
}

void	PhoneBook::_add()
{
	std::string input;
	static int index = 0;

	if(index == 8)
		index = 0;
	input.clear();
	while(input.empty())
	{
		std::cout << "\tEnter first name: ";
		getline(std::cin, input);
		if(std::cin.eof())
			exit(1);
	}
	Contacts[index].set_fname(input);
	input.clear();
	while(input.empty())
	{
		std::cout << "\tEnter last name: ";
		getline(std::cin, input);
		if(std::cin.eof())
			exit(1);
	}
	Contacts[index].set_lname(input);
	input.clear();
	while(input.empty())
	{
		std::cout << "\tEnter nickname: ";
		getline(std::cin, input);
		if(std::cin.eof())
			exit(1);
	}
	Contacts[index].set_nickname(input);
	input.clear();
	while(input.empty())
	{
		std::cout << "\tEnter phone number: ";
		getline(std::cin, input);
		if(std::cin.eof())
			exit(1);
		else if (!isnum(input))
		{
			
			std::cout << "\tEnter a valid phone number!\n";
			input.clear();
		}
		
	}
	Contacts[index].set_phone(input);
	input.clear();
	while(input.empty())
	{
		std::cout << "\tEnter dark secret: ";
		getline(std::cin, input);
		if(std::cin.eof())
			exit(1);
	}
	Contacts[index].set_secret(input);
	input.clear();
	index++;
}

int PhoneBook::_get_size(void)
{
	for(int i = 0; i < 8; i++)
	{
		if(Contacts[i].get_fname().empty())
			return i;
	}
	return 0;
}

void	PhoneBook::_display(int size)
{
	if(!size)
	{
		std::cout << "Phonebook is empty, please add a contact!" << std::endl; 
		return ;
	}
	std::cout << "\n";
	std::cout << std::setw(10) <<"INDEX" <<"|";
	std::cout << std::setw(10) <<"FIRST NAME" <<"|";
	std::cout << std::setw(10) <<"LAST NAME" <<"|";
	std::cout << std::setw(10) <<"NICKNAME" <<"|\n";
	std::cout << "____________________________________________\n";
	for(int i = 0; i < size; i++)
	{
		std::cout << std::setw(10) <<(i + 1) <<"|";
		if(Contacts[i].get_fname().length() > 10)
			std::cout << std::setw(10) << Contacts[i].get_fname().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) <<Contacts[i].get_fname() <<"|";
		if(Contacts[i].get_lname().length() > 10)
			std::cout << std::setw(10) << Contacts[i].get_fname().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) <<Contacts[i].get_lname() <<"|";
		if(Contacts[i].get_lname().length() > 10)
			std::cout << std::setw(10) << Contacts[i].get_fname().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) <<Contacts[i].get_nickname() << "|\n";
	}
}



void PhoneBook::_search()
{
	std::string input;
	int index;
	int size;

	size = _get_size();
	std::cout << "size" << size << std::endl; 
	_display(size);
	std::cout << "\nEnter index: ";
	getline(std::cin,input);
	if(!isnum(input))
	{
		std::cout << "invalid index\n";
		return ;	
	}
	index = std::atoi(input.c_str());
	if(index > 8 || index <= 0 || index > size)
	{
		std::cout << "invalid index\n";
		return ;
	}
	std::cout << "\tFirst Name  : " <<Contacts[index - 1].get_fname() << std::endl;
	std::cout << "\tLast Name   : " <<Contacts[index - 1].get_lname() << std::endl;
	std::cout << "\tNickname    : " <<Contacts[index - 1].get_nickname() << std::endl;
	std::cout << "\tPhone Number: " <<Contacts[index - 1].get_phone() << std::endl;
	std::cout << "\tDark Secret : " <<Contacts[index - 1].get_secret() << std::endl;
}

int main()
{
	PhoneBook pb;
	std::string input;
	
	std::cout << ">> : " ;
	while(getline(std::cin , input))
	{
		if(input == "ADD")
			pb._add();
		else if (input == "SEARCH")
			pb._search();
		else if (input == "EXIT")
		{
			std::cout << "Exit!" << std::endl;
			exit(0); 
		}
		else
			std::cout << "Invalid command!" << std::endl;
		
		std::cout << ">> : " ;
	}
}