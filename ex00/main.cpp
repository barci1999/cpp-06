/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:25:13 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/21 20:19:43 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"
#include"ParserScalar.hpp"
#include"AParser.hpp"
int main(int argc,char **argv)
{
	try
	{
		ParserScalar Progam(argc,argv);
		std::string* temp = Progam.get_args();
		ScalarConverter::convert(temp[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}