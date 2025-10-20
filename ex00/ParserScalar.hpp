/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserScalar.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:21:31 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/20 19:45:32 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERSCALAR_HPP
# define PARSERSCALAR_HPP
# include "AParser.hpp"

class ParserScalar : public AParser
{
public:
	ParserScalar(/* args */);
	ParserScalar(int argc,char **argv);
	ParserScalar(const ParserScalar& other);
	ParserScalar& ParserScalar::operator=(const ParserScalar& other);
	~ParserScalar();

	void check_valid();
};

#endif
