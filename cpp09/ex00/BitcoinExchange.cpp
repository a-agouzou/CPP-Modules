/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:59:15 by aagouzou          #+#    #+#             */
/*   Updated: 2023/12/19 13:57:43 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if(this != &other)
		data_base = other.data_base;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

static bool isleap_year(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
	else 
        return true;
}

static bool is_valid_date(std::string& year, std::string& month, std::string&day)
{
	int y, m, d;

	y = atoi(year.c_str());
	m = atoi(month.c_str());
	d = atoi(day.c_str());
	if((y < 2009 || m > 12 || m <= 0 || d > 31 || d <= 0) || (y <= 2009 && m <= 1 && d <= 1))
		return 0;
	if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return 0;
	else if (m == 2)
	{
		if((isleap_year(y) && d > 29) || (!isleap_year(y) && d > 28))
			return 0;
	}
	return 1;
}

static bool is_valid_value(std::string& value)
{
	size_t i = 0;
	int count = 0;
	if(value[i] == '-' || value[i] == '+')
		i++;
	for(; i < value.size(); i++)
	{
		if(value[i] != '.' && !isdigit(value[i]))
			return 0;
		if(value[i] == '.')
			count++;
	}
	if(count > 1 || ((count == 1  || value[0] == '+' || value[0] == '-') && value.size() == 1) || value[0] == '.' || value[value.length() - 1] == '.')
		return 0;
	return 1;
}

static void convert_date_to_sec(std::time_t &date, std::string &_date)
{
	std::tm time;
    std::memset(&time, 0, sizeof(time));
    strptime(_date.c_str(), "%Y-%m-%d", &time);
    date = mktime(&time);
}

static bool isvalid(std::string &line, std::time_t &date, std::string& value)
{
	std::string year, month, day, _date;
	for(size_t i = 0 ; i < 10 ; i++)
	{
		if(((i == 4 || i == 7) && line[i] != '-') || (!isdigit(line[i]) && i != 4 && i != 7))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return 0;
		}
	}
	year = line.substr(0,4);
	month = line.substr(5,2);
	day = line.substr(8,2);
	if(!is_valid_date(year, month, day) || line.substr(10,3) != " | ")
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return 0;
	}
	value = line.substr(13);
	if(!is_valid_value(value) || value.empty())
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return 0;
	}
	_date = line.substr(0,10);
	convert_date_to_sec(date, _date);
	return 1;
}
static void	fill_data_base(std::ifstream& data, std::map<std::time_t,double>& data_base)
{
	std::string line, date, price;
	std::time_t _date;
	std::getline(data, line);
	if(line.empty())
	{
		std::cout << "invalid data" << std::endl;
		exit(1);
	}
	while(std::getline(data, line))
	{
		date = line.substr(0,10);
		price = line.substr(11);
		convert_date_to_sec(_date,date);
		data_base[_date] = strtod(price.c_str(),NULL);
	}
}

void printoutput(std::map<std::time_t,double>& data_base,std::time_t& date, std::string& value, std::string& line)
{
	double _value = strtod(value.c_str(), NULL);
	if(_value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (_value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	std::map<std::time_t,double>::iterator it = data_base.lower_bound(date);
	if(it != data_base.begin() && it->first != date)
		it--;
	std::cout << line.substr(0,10) << " => " << line.substr(13) << " = " << it->second * _value << std::endl;
	
}

void BitcoinExchange::btc(std::ifstream& data, std::ifstream& input)
{
	std::string line, value, date_;
	std::time_t date;
	fill_data_base(data, data_base);
	std::getline(input, line);
	if(line != "date | value")
	{
		std::cout << "Error: first line must follow this format. data | value" << std::endl;
		return ;
	}
	while(std::getline(input,line))
	{
		if(line.size() < 11)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue; 
		}
		if(!isvalid(line,date ,value))
			continue;
		printoutput(data_base,date,value, line);
	}

}