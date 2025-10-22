/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserScalar.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:21:31 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/22 11:31:07 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERSCALAR_HPP
# define PARSERSCALAR_HPP
# include "AParser.hpp"
# include <limits.h>
#include <cstdlib>
#include <cerrno> 


class ParserScalar : public AParser
{
public:
	ParserScalar(/* args */);
	ParserScalar(int argc,char **argv);
	ParserScalar(const ParserScalar& other);
	ParserScalar& operator=(const ParserScalar& other);
	~ParserScalar();

	void check_valid();
	bool is_char()const;
	bool is_int()const;
	bool is_float()const;
	bool is_double()const;
};

#endif
