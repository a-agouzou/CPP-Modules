/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:21:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/30 16:11:59 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void) other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void) other;
    return *this;
}


bool is_char(const std::string& literal)
{
    return (literal.size() == 1) && !isnumber(literal[0]);
}

bool is_int(const std::string& literal)
{
    int i = 0;
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    for(; i < (int)literal.size(); i++)
    {
        if(!isnumber(literal[i]))
            return false;
    }
    return true;
}

bool is_float(const std::string& literal)
{
    int dot_count = 0;
    int i=0;
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    for(; i < (int)(literal.size() - 1); i++)
    {
        if(!isnumber(literal[i]) && literal[i] != '.')
            return false;
        if(literal[i] == '.')
            dot_count++;
    }
    if(dot_count != 1 || literal[literal.size() - 1] != 'f')
            return false;   
    return true;
}

bool is_double(const std::string& literal)
{
    int i=0;
    int dot_count = 0;
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    for(; i < (int)(literal.size()); i++)
    {
        if(!isnumber(literal[i]) && literal[i] != '.')
            return false;
        if(literal[i] == '.')
            dot_count++;
    }
    if(dot_count != 1)
            return false;   
    return true;
}

bool contain_comma(double value)
{
    std::stringstream ss;
    ss << value;
    std::string numberString = ss.str();
    if (numberString.find('.') != std::string::npos)
        return true;
    return false;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
    if(is_char(literal))
    {
        char value = literal[0];
        if(isprint(value))
            std::cout << "char: '" << (value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" <<  std::endl;
        std::cout << "int: " << static_cast<int>(value) <<std::endl;
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    }
    else if (is_double(literal) || is_int(literal) || is_float(literal))
    {
        std::stringstream stream(literal);
        double value;
        stream >> value;
        bool contain = contain_comma(value);
        if(isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" <<  std::endl;
        std::cout << "int: " << static_cast<int>(value) <<std::endl;
        if(contain)
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        if(contain)
            std::cout << "double: " << (value) << std::endl;
        else
            std::cout << "double: " << (value) << ".0" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}