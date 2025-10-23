/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:54:20 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 14:04:05 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main() 
{
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
        std::cout << "✅ Success: pointers are equal!" << std::endl;
    else
        std::cout << "❌ Failure: pointers differ!" << std::endl;

    std::cout << "\nData content after deserialization:" << std::endl;
    std::cout << "ID: " << ptr->id << std::endl;
    std::cout << "Name: " << ptr->name << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;

    return 0;
}