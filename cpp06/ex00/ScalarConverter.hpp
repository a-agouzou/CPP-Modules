#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>


class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        static void convert(const std::string& literal);
        ~ScalarConverter();
};

#endif