/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:39:05 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/08 18:30:34 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default destructor called" << std::endl;
}

bool is_char(std::string literal)
{
    if (isalpha(literal[0])  && literal.length() == 1)
        return true;
    return false;
}

bool is_int()
{
    return false;
}

bool is_float(std::string literal)
{
    size_t i;
    size_t dot_count;

    dot_count = 0;
    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (literal[i] != '\0')
    {
        if (!std::isdigit(literal[i]))
        {
            if (literal[i] == '.')
            {
                dot_count++;
                if (dot_count > 1 || std::isdigit(literal[i + 1]) == 0 || literal[i + 1] == '\0')
                    return (false);
            }
            else if ((literal[i] == 'F' || literal[i] == 'f') && dot_count == 1 && literal[i + 1] == '\0')
                return (true);
            else
                return (false);
        }
        i++;
    }
    return (false);
}

bool is_double()
{
    return false;
}

void    ScalarConverter::detectType(std::string literal)
{
    if (is_char(literal))
        std::cout << "It must be a char" << std::endl;
    if (is_float(literal))
        std::cout << "It must be a float" << std::endl;
}
