/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AParser.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:47:47 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/21 12:59:24 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HPP
# define PARSE_HPP
# include "string"
# include "iostream"
class AParser
{
protected:
	int _argc;
	char **_old_argv;
	std::string* _args;
	bool _is_valid;
public:
	AParser(/* args */);
	AParser(int argc,char**argv);
	AParser(const AParser& other);
	AParser& operator=(const AParser& other);
	virtual ~AParser();
	
	class ExceptionError : public std::exception
		{
			const char* _msg;
			public:
				explicit ExceptionError(const char* msg) : _msg(msg) {}
				virtual const char* what() const throw(){
					return(_msg);
				}
		};
	int get_Argc() const;
	std::string* get_args() const;
	char ** get_old_argv() const;
	bool get_Is_valid() const;
	virtual void check_valid() = 0;
};

#endif