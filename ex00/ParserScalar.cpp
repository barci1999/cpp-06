/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserScalar.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:32 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/20 19:48:42 by pablalva         ###   ########.fr       */
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
void ParserScalar::check_valid()
{
	if(this->_argc > 2)
		throw InvalidNbrArguments();
}
