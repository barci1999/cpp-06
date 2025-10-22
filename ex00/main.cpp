/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:25:13 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/22 19:16:21 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"
#include"ParserScalar.hpp"
#include"AParser.hpp"
int main(int argc,char **argv)
{
	try
	{
		ParserScalar program(argc,argv);
		program.check_valid();
		std::string* temp = program.get_args();
		ScalarConverter::convert(temp[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}