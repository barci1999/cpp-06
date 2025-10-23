/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:54:14 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 13:43:57 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

Serializer::Serializer(){
	// std::cout << "Default constructor called." << std::endl;
}
Serializer::Serializer(const Serializer& other){
	// std::cout << "Copy constructor called." << std::endl;
	*this = other;
}
Serializer& Serializer::operator=(const Serializer& other){
	// std::cout << "Assignment operator called." << std::endl;
	(void)other;
	return *this;
}
Serializer::~Serializer(){}
uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));	
}
