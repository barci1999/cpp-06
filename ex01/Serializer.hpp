/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:54:17 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 13:50:39 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA
# define DATA
# include<string>
# include<iostream>
struct Data
{
	int id;
	std::string name;
	float value;
};
#endif

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
class Serializer
{
public:
	Serializer(/* args */);
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	virtual ~Serializer() = 0;

	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
		
#endif