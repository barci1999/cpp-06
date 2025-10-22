/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserScalar.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:32 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/22 19:06:09 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserScalar.hpp"

ParserScalar::ParserScalar() : AParser(0,NULL)
{
	//std::cout << "Deafult constructoa called." << std::endl;
}
ParserScalar::ParserScalar(const ParserScalar&other): AParser(other)
{
	//std::cout << "Copy constructor called." << std::endl;
}
ParserScalar::ParserScalar(int argc,char**argv): AParser(argc,argv)
{
	//std::cout << "Parmetered constructor called." << std::endl;
}
ParserScalar& ParserScalar::operator=(const ParserScalar& other)
{
	//std::cout << "Assignment operator called." << std::endl;
	if (this == &other)
	{	
		return *this;
	}
	AParser::operator=(other);
	return *this;
}
ParserScalar::~ParserScalar()
{
	//std::cout << "Destructor called." << std::endl;
}
bool ParserScalar::is_char() const
{
	if(this->_args[1].size() != 1 || !std::isprint(this->_args[1][0]) || std::isdigit(this->_args[1][0]))
		return false;
	return true;
}
bool ParserScalar::is_int() const
{	
	int i = 0;
	if (this->_args[1][i] == '+' || this->_args[1][i] == '-')
		i++;
	else if (!std::isdigit(this->_args[1][i]))
		return false;
	while (this->_args[1][i] && std::isdigit(this->_args[1][i]))
		i++;
	if(this->_args[1][i] != '\0')
		return(false);
	char *end;
    errno = 0; 
    long value = std::strtol(this->_args[1].c_str(), &end, 10);
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
    {
        return false;
    }
	return(true);	
}
bool ParserScalar::is_float() const
{
    if (this->_args[1].size() < 2)
        return false;
    if (this->_args[1] ==  "-inff" ||this->_args[1] == "+inff" || this->_args[1] =="nanf")
        return true;
    size_t i = 0;
    bool has_dot = false;
    bool has_digit = false;
    if (this->_args[1][i] == '+' || this->_args[1][i] == '-')
        i++;
    for (; i < this->_args[1].size(); i++)
    {
        char c = this->_args[1][i];
        if (std::isdigit(c))
            has_digit = true;
        else if (c == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (c == 'f')
		{
            if (has_digit && has_dot && i == this->_args[1].size() - 1)
    			return true;
			else
    			return false;
		}
        else
            return false;
    }
    return false;
}
bool ParserScalar::is_double() const
{
    if (this->_args[1].size() < 2)
        return false;
    if (this->_args[1] ==  "-inf" ||this->_args[1] == "+inf" || this->_args[1] =="nan")
        return true;
    size_t i = 0;
    bool has_dot = false;
    bool has_digit = false;
    if (this->_args[1][i] == '+' || this->_args[1][i] == '-')
        i++;
    for (; i < this->_args[1].size(); i++)
    {
        char c = this->_args[1][i];
        if (std::isdigit(c))
            has_digit = true;
        else if (c == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else
            return false;
    }
    return has_digit;
}

void ParserScalar::check_valid()
{
    if(this->_argc != 2)
    {
        throw ExceptionError("Error: invalid number of arguments.");
    }
	if (this->_args[1].empty() || this->_args[1].find_first_not_of(" \t\n\r") == std::string::npos)
		throw ExceptionError("Error: empty arguments");
	bool (ParserScalar::*functions[4])() const = {
		&ParserScalar::is_char,
		&ParserScalar::is_int,
		&ParserScalar::is_float,
		&ParserScalar::is_double
	};
	for (int i = 0; i < 4; i++)
	{
		if ((this->*functions[i])())
		{
			return;
		}
	}
	throw ExceptionError("Error: invalid argument type.");
}
