/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:37:27 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/22 18:51:39 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "string"
# include "iostream"
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include<limits.h>
class ScalarConverter
{
private:

public:
	ScalarConverter(/* args */);
	ScalarConverter(std::string _to_scalar);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	virtual ~ScalarConverter() = 0;

	class ExceptionError : public std::exception
		{
			const char* _msg;
			public:
				explicit ExceptionError(const char* msg) : _msg(msg) {}
				virtual const char* what() const throw(){
					return(_msg);
				}
		};
	std::string getTo_scalar() const;
	static void convert(std::string _to_scalar);
};
std::ostream &operator<<(std::ostream& out,const ScalarConverter& to_print);
#endif