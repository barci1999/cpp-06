/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:22:08 by pablalva          #+#    #+#             */
/*   Updated: 2025/10/23 16:05:42 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <ctime>
# include <cstdlib>
class Base
{
public:
	virtual~Base();
};
Base* generate(void);
void identify(Base* p);
void identify(Base& p);
#endif
