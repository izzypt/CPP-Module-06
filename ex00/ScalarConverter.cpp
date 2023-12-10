/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:39:05 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 21:30:29 by smagalha         ###   ########.fr       */
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
        (void)src;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default destructor called" << std::endl;
}

bool ScalarConverter::is_char(std::string literal)
{
    if (isalpha(literal[0]) && literal.length() == 1)
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
                    return (false);
            }
            else if ((literal[i] == 'D' || literal[i] == 'd') && dot_count == 1 && literal[i + 1] == '\0')
                return (true);
            else
                return (false);
        }
        i++;
    }
    return(dot_count == 1 ? true : false);
}

void    ScalarConverter::detectType(std::string literal)
{
    if (handle_pseudo_literals(literal) == false)
    {
        if (is_char(literal))
            literal_to_char(literal);
        if (is_int(literal))
            literal_to_int(literal);
        if (is_double(literal))
            literal_to_double(literal);
        if (is_float(literal))
            literal_to_float(literal);   
    }
}

bool ScalarConverter::handle_pseudo_literals(std::string literal)
{
    std::string charMsg = "char: impossible";
    std::string intMsg = "int: impossible";
    
    if (literal == "nanf" || literal == "nan")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
        return (true);
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
        return (true);
    }
    else if (literal == "inff" || literal == "inf" || literal == "+inff" || literal == "+inf")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: inff" << std::endl << "double: inf" << std::endl;
        return (true);
    }
    return (false);
}

void    ScalarConverter::literal_to_char(std::string literal)
{
    char c;

    c = literal[0];
    if (literal.length() == 1)
    {
        std::cout << "char: " << "'" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;

    }
}

void    ScalarConverter::literal_to_int(std::string literal)
{
    long i;

    i = std::atoll(literal.c_str());
    std::cout << "char: ";
    if ((i >= 0 && i < 32) || (i == 127))
        std::cout << "Non displayable" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    if (i <= std::numeric_limits<long>::max() && i >= std::numeric_limits<long>::min() &&  literal.length() < 10)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::abs(i) <= std::numeric_limits<float>::max())
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    if (std::abs(i) <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
    return ;
}

void    ScalarConverter::literal_to_double(std::string literal)
{
    double d;
    
    if (handle_pseudo_literals(literal) == true)
        return ;
    d = std::atof(literal.c_str());
    std::cout << "char: ";
    if ((d >= 0 && d < 32) || (d == 127))
        std::cout << "Non displayable" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    if (d <= std::numeric_limits<long>::max() && d >= std::numeric_limits<long>::min() &&  literal.length() < 10)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::abs(d) <= std::numeric_limits<float>::max())
    {
        if (static_cast<float>(d) == static_cast<int>(d))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    if (std::abs(d) <= std::numeric_limits<double>::max())
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
    return ;
}

void    ScalarConverter::literal_to_float(std::string literal)
{
    float f;

    if (handle_pseudo_literals(literal) == true)
        return ;
    f = std::strtof(literal.c_str(), NULL);
    std::cout << "char: ";
    if ((f >= 0 && f < 32) || (f == 127))
        std::cout << "Non displayable" << std::endl;
    else if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    if (f <= std::numeric_limits<long>::max() && f >= std::numeric_limits<long>::min() &&  literal.length() < 10)
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (std::fabs(f) <= std::numeric_limits<float>::max())
    {
        if (static_cast<float>(f) == static_cast<int>(f))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    if (std::fabs(f) <= std::numeric_limits<double>::max())
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
    return ;
}