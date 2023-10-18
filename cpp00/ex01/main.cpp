/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:03:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/18 13:51:24 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void PhoneBook::_search()
{
	int input;

	std::cout << "\n";
	std::cout << std::setw(10) <<"INDEX" <<"|";
	std::cout << std::setw(10) <<"FIRST NAME" <<"|";
	std::cout << std::setw(10) <<"LAST NAME" <<"|";
	std::cout << std::setw(10) <<"NICKNAME" <<"|\n";
	std::cout << "____________________________________________\n";
	for(int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) <<(i + 1) <<"|";
		std::cout << std::setw(10) <<Contacts[i].get_fname() <<"|";
		std::cout << std::setw(10) <<Contacts[i].get_lname() <<"|";
		std::cout << std::setw(10) <<Contacts[i].get_nickname() << "|\n";
	}
	
	std::cout << "\nEnter index: ";
	std::cin >> input;
	if(input > 8 || input <= 0)
	{	
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "invalid index\n";
		return ;
	}
	std::cin.ignore();
	std::cout << std::setw(10) <<Contacts[input - 1].get_fname() <<"|";
	std::cout << std::setw(10) <<Contacts[input - 1].get_lname() <<"|";
	std::cout << std::setw(10) <<Contacts[input - 1].get_nickname() << "|";
	std::cout << std::setw(10) <<Contacts[input - 1].get_phone() << "|";
	std::cout << std::setw(10) <<Contacts[input - 1].get_secret() << "|\n";
}

int main()
{
	PhoneBook pb;
	std::string input;
	

	int i = sizeof(pb.Contacts);
	std::cout << i << std::endl;

	// for(int  i = 0; i < 8 ; i++)
	// {
	// 	if(pb.Contacts[i].)
	// }
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
			std:: cout << "Invalid command!" << std::endl;
		
		std::cout << ">> : " ;
	}
}