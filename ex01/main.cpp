/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:54:20 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 14:25:38 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main() 
{
	{
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Correct use os serialize and deserialize" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		Data data;
		data.id = 42;
		data.name = "perro";
		data.value = 3.14159;

		std::cout << "Original Data address: " << &data << std::endl;

		uintptr_t raw = Serializer::serialize(&data);
		std::cout << "Serialized uintptr_t: " << raw << std::endl;

		Data* ptr = Serializer::deserialize(raw);
		std::cout << "Deserialized Data address: " << ptr << std::endl;

		if (ptr == &data)
			std::cout << "Success: pointers are equal!" << std::endl;
		else
			std::cout << "Failure: pointers differ!" << std::endl;

		std::cout << "\nData content after deserialization:" << std::endl;
		std::cout << "ID: " << ptr->id << std::endl;
		std::cout << "Name: " << ptr->name << std::endl;
		std::cout << "Value: " << ptr->value << std::endl;
	}
	{
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "Incorrect use os serialize and deserialize" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		Data data = {42, "perro", 3.14};

		uintptr_t raw = Serializer::serialize(&data);
		Data* ptr = Serializer::deserialize(raw);

		std::cout << "Deserialized Data (correct): " << ptr << std::endl;
		std::cout << "ID: " << ptr->id << std::endl;
		std::cout << "Name: " << ptr->name << std::endl;
		std::cout << "Value: " << ptr->value << std::endl;

		uintptr_t fake = 12345678;
		Data* fake_ptr = Serializer::deserialize(fake);

		std::cout << "\nDeserialized Data (fake): " << fake_ptr << std::endl;
		//std::cout << fake_ptr->id << std::endl; 
	}
    return 0;
}