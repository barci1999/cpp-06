/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:25:13 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/20 18:28:28 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"
int main(int argc,char **argv)
{
	if (argc < 2)
	{
		return(std::cout<<"invalid number argumens."<<std::endl,1);
	}
	std::string conver = argv[1];
	ScalarConverter::convert(conver);
}