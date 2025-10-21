/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:49:30 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/21 20:40:24 by pablalva         ###   ########.fr       */
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
void ScalarConverter::convert(std::string _to_scalar)
{
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	try
	{
		f = std::stof(_to_scalar);
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}