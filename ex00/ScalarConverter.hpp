/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:29:14 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/08 17:59:59 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream> // to use cout
#include <string> // to use string
#include <iomanip> // to use setprecision
#include <cstdlib> // to use atof
#include <climits> // to use INT_MAX
#include <cfloat> // to use FLT_MAX
#include <cmath>
#include <limits> // to use numeric_limits

class ScalarConverter 
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        static void convert(std::string literal);
        static void detectType(std::string literal);
};

bool is_char(std::string literal);
bool is_float(std::string literal);
bool is_double();
bool is_int();

#endif