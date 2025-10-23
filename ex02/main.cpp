/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:22:04 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 16:02:26 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
int main(void)
{
	Base* base = generate();

    std::cout << "Identify using pointer: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;
    return 0;
}