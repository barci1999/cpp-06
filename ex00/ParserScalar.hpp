/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserScalar.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:21:31 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/21 19:13:59 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERSCALAR_HPP
# define PARSERSCALAR_HPP
# include "AParser.hpp"
# include <limits.h>

class ParserScalar : public AParser
{
public:
	ParserScalar(/* args */);
	ParserScalar(int argc,char **argv);
	ParserScalar(const ParserScalar& other);
	ParserScalar& ParserScalar::operator=(const ParserScalar& other);
	~ParserScalar();

	void check_valid();
	bool is_char()const;
	bool is_int()const;
	bool is_float()const;
	bool is_double()const;
};

#endif
