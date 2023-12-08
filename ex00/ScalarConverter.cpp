/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:39:05 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/08 22:34:38 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}


ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &src)
    {
        (void)src;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default destructor called" << std::endl;
}

bool ScalarConverter::is_char(std::string literal)
{
    if (isalpha(literal[0])  && literal.length() == 1)
        return true;
    return false;
}

bool ScalarConverter::is_int(std::string literal)
{
    size_t i;
    long int temp;

    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (literal[i] != '\0')
    {
        if (!std::isdigit(literal[i]) || i > 10)
            return (false);
        i++;
    }
    temp = std::atol(literal.c_str());
    if (temp <= std::numeric_limits<int>::max() && temp >= std::numeric_limits<int>::min())
        return (true);
    else
        return (false);
}

bool ScalarConverter::is_float(std::string literal)
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

bool ScalarConverter::is_double(std::string literal)
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
                {
                    return (false);
                }
            }
            else if ((literal[i] == 'D' || literal[i] == 'd') && dot_count == 1 && literal[i + 1] == '\0')
            {
                return (true);
            }
            else
            {
                return (false);
            }
        }
        i++;
    }
    return(dot_count == 1 ? true : false);
}

void    ScalarConverter::detectType(std::string literal)
{
    if (is_char(literal))
        std::cout << "It must be a char" << std::endl;
    if (is_float(literal))
        std::cout << "It must be a float" << std::endl;
    if (is_int(literal))
        std::cout << "It must be a int" << std::endl;
    if (is_int(literal))
        std::cout << "It must be a int" << std::endl;
}
