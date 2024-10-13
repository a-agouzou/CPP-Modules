/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:13 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/18 21:23:23 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
	
}

Rpn::~Rpn()
{
	
}
Rpn& Rpn::operator=(const Rpn& other)
{
	if(this != &other)
		stk = other.stk;
	return *this;
}

Rpn::Rpn(const Rpn& other)
{
	*this = other;
	
}

static size_t extract_arg(std::string& str, std::string& token, size_t pos)
{
	while(pos < str.size() && isspace(str[pos]))
		pos++;
	size_t start = pos;
	size_t len  = 0;
	while(pos < str.size() && !isspace(str[pos]))
	{
		pos++;
		len++;	
	}
	token = str.substr(start, len);
	if(pos == str.size())
		pos = std::string::npos;
	return pos;
}


static bool isNum(std::string& token)
{
	if((token == "-" || token == "+" || token == "/" || token == "|") && token.size() == 1)
		return 0;
	size_t i = 0;
	if(i < token.size() && (token[i] == '+' || token[i] == '-'))
		i++;
	for(;i < token.size(); i++)
	{
		if(!isdigit(token[i]))
			return 0;
	}
	return 1;
}

static void trim_spaces(std::string& token)
{
	std::string::iterator it = token.begin();
	while (it != token.end() && isspace(*it))
		it++;
	token.erase(token.begin(), it);
	std::string::reverse_iterator revit = token.rbegin();
	while (revit != token.rend() && isspace(*revit))
		revit++;
	token.erase(revit.base(), token.end());
}

bool Rpn::rpn(std::string str)
{
	std::string token;
	size_t pos = 0;
	int value, operand1, operand2, res;
	trim_spaces(str);
	if(str.find_first_not_of("-+*/1234567890\t\v\n ") != std::string::npos || str == "" || str.length() <= 1)
		return 0;
	while(pos != std::string::npos )
	{
		token.clear();
		pos = extract_arg(str, token, pos);
		if(isNum(token))
		{
			value = atoi(token.c_str());
			if(value < 0 || value >= 10)
				return 0;
			stk.push(value);
		}
		else
		{
			if(stk.size() < 2)
				return 0;
			operand1 = stk.top();
			stk.pop();
			operand2 = stk.top();
			stk.pop();
			if(token == "+")
				res = operand2 + operand1;
			else if (token == "-")
				res = operand2 - operand1;
			else if (token == "*")
				res = operand2 * operand1;
			else if (token == "/")
			{
				if(operand1 == 0)
					return 0;
				res = operand2 / operand1;
			}
			else
				return 0;
			stk.push(res);
		}
	}
	if(stk.size() != 1)
		return 0;
	else
		std::cout << stk.top() << std::endl;
	return 1;
}
