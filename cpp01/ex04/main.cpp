/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:12:24 by aagouzou          #+#    #+#             */
/*   Updated: 2023/10/28 11:27:40 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace(std::string& buffer, std::string s1, std::string s2) 
{
	if(s1.empty())
		return ;
    size_t pos = 0;
    while ((pos = buffer.find(s1, pos)) != std::string::npos)
	{
        buffer.erase(pos, s1.length());
        buffer.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char *argv[])
{
	std::string in;
	std::string out;
	std::string s1;
	std::string s2;

	if(argc != 4)
	{
		std::cout << "invalid arguments" << std::endl;
		return 0;
	}
	in = argv[1];
	out = in + ".replace";
	s1 = argv[2];
	s2 = argv[3];
	
	std::ifstream infile(in);
	if(!infile.is_open())
	{
		std::cout << "Failed to open the file" << std::endl;
		return 1;
	}
	std::string line;
	std::string buffer;
	while(std::getline(infile, line))
	{
		buffer += line;
		if(!infile.eof())
			buffer += '\n';
	}
	if(buffer.empty())
	{
		std::cout << "Empty File" << std::endl;
		return 1;
	}
	std::ofstream outfile(out);
	if(!outfile.is_open())
	{
		std::cout << "Failed to open out the file" << std::endl;
		infile.close();
		return 1;
	}
	replace(buffer,s1,s2);

	outfile << buffer;
	outfile.close();
	return 0;
}
