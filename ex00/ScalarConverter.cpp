/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:49:30 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/22 19:12:36 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called." << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;	
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;	
}
ScalarConverter::~ScalarConverter()
{}
static void print_char(double to_print)
{
	if(std::isnan(to_print) || std::isinf(to_print) || to_print < CHAR_MIN || to_print > CHAR_MAX)
		std::cout << "char: imposible" << std::endl;
	else
	{
		char c = static_cast<char>(to_print);
		if(std::isprint(c))
			std::cout << "char: " << '\'' << c << '\'' << std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
	}
}
static void print_int(double to_print)
{
	if (to_print > INT_MAX || to_print < INT_MIN || std::isnan(to_print) || std::isinf(to_print))
		std::cout << "int: imposible" << std::endl;
	else
	{
		int i = static_cast<int>(to_print);
		std::cout << "int: " << i << std::endl;
	}
}
static void print_double(double to_print)
{
	if(std::isnan(to_print))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(to_print))
	{
		if (to_print > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
	{
		if(to_print == static_cast<int>(to_print))
			std::cout << "double: " << to_print << ".0" << std::endl;
		else
			std::cout << "double: " << to_print << std::endl;
		
	}
}
static void print_float(double to_print)
{
	if(std::isnan(to_print))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(to_print))
	{
		if (to_print > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
	{
		float f = static_cast<float>(to_print);
		
		if(f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" <<std::endl;
		
	}
}
void ScalarConverter::convert(std::string _to_scalar)
{
    double d = 0.0;

    char *end;
    errno = 0;
    d = std::strtod(_to_scalar.c_str(), &end);
    if (*end != '\0') 
	{
		if (*end == 'f' && *(end + 1) == '\0'){}
        else
        {
            throw ExceptionError("Error: failed to cast.");
        }
	}
    if (errno == ERANGE)
		throw ExceptionError("Error: out of range.");
	print_char(d);
	print_int(d);
	print_float(d);
	print_double(d);
}