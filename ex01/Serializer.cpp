/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:03:00 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 18:18:29 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer constructor should not be called because it is private" << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
    std::cout << "Serializer copy constructor should not be called because it is private" << std::endl;
    *this = src;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor should not be called because constructor is private" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    std::cout << "Serializer assignation operator should not be called because it is private" << std::endl;
    if (this != &src)
        (void)src;
    return (*this);
}

/* serialize() takes a pointer to Data as a parameter and returns a uintptr_t. 
 * The function should cast the pointer to uintptr_t and return it.
 * reinterpret_cast is used to convert a pointer into an integer type.
 */
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/* deserialize() takes a uintptr_t as a parameter and returns a pointer to Data. 
 * The function should cast the uintptr_t to a pointer and return it.
 */
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}