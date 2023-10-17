/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:03:14 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/17 19:18:52 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	_add(PhoneBook *pb)
{
	std::string input;
	static int index = 0;
	
	std::cout << "Enter first name: ";
	getline(std::cin, input);
	pb->Contacts[index].set_fname(input);
	std::cout << "Enter last name: ";
	getline(std::cin, input);
	pb->Contacts[index].set_lname(input);
	std::cout << "Enter nickname: ";
	getline(std::cin, input);
	pb->Contacts[index].set_nickname(input);
	std::cout << "Enter phone number: ";
	getline(std::cin, input);
	pb->Contacts[index].set_phone(input);
	std::cout << "Enter dark secret: ";
	getline(std::cin, input);
	pb->Contacts[index].set_secret(input);
	index++;
	return index;
}

void	_display(PhoneBook pb, int index)
{
	
	std::cout << "____________________________________________\n";
	for(int i = 0; i < index; i++)
	{
		std::cout << std::setw(10) <<(i + 1) <<"|";
		std::cout << std::setw(10) <<pb.Contacts[i].get_fname() <<"|";
		std::cout << std::setw(10) <<pb.Contacts[i].get_lname() <<"|";
		std::cout << std::setw(10) <<pb.Contacts[i].get_nickname() << "|\n";
	}
}

void _search(PhoneBook pb, int index)
{
	int input;
	
	_display(pb, index);
	std::cout << "Enter index: ";
	std::cin >> input;
	if(input > index + 1 || input > 8 || input <= 0)
	{	
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "invalid index\n";
		return ;
	}
	std::cin.ignore();
	std::cout << std::setw(10) <<pb.Contacts[input - 1].get_fname() <<"|";
	std::cout << std::setw(10) <<pb.Contacts[input - 1].get_lname() <<"|";
	std::cout << std::setw(10) <<pb.Contacts[input - 1].get_nickname() << "|";
	std::cout << std::setw(10) <<pb.Contacts[input - 1].get_phone() << "|";
	std::cout << std::setw(10) <<pb.Contacts[input - 1].get_secret() << "|\n";
}

int main()
{
	PhoneBook pb;
	std::string input;
	int index;
	
	std::cout << ">> : " ;
	while(getline(std::cin , input))
	{
		if(input == "ADD")
			index = _add(&pb);
		else if (input == "SEARCH")
			_search(pb, index);
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