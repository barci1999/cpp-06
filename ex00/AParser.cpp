/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AParserr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:47:51 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/20 19:20:05 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AParser.hpp"

AParser::AParser()
{
	//std::cout << "Default constructor called." << std::endl;
	this->_argc  = 0;
	this->_old_argv = NULL;
	this->_is_valid = false;
	this->_args = NULL;
}
AParser::AParser(int argc,char **argv) : _argc(argc) , _old_argv(argv), _is_valid(false)
{
	//std::cout << "Parametered constructor called." <<  std::endl;
	this->_args = new std::string[_argc];
		for (size_t i = 0; i < this->_argc; i++)
		{
			_args[i] = std::string(_old_argv[i]);
		}
}
AParser::AParser(const AParser& other)
{
	//std::cout << "Copy constructor called." << std::endl;
	this->_argc = other._argc;
	this->_old_argv = other._old_argv;
	this->_is_valid = other._is_valid;
	this->_args = other._args;
}
AParser& AParser::operator=(const AParser& other)
{
	//std::cout << "assignment operator called." << std::endl;
	if (this == &other)
	{
		return *this;	
	}
	this->_argc = other._argc;
	this->_old_argv = other._old_argv;
	this->_is_valid = other._is_valid;
	this->_args = other._args;
	return *this;
}
AParser::~AParser()
{
	//std::cout << "Destructor called." << std::endl;
	delete[]_args;
}