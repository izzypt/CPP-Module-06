/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:29:14 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 21:27:46 by smagalha         ###   ########.fr       */
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
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
    public:
        ScalarConverter& operator=(ScalarConverter const &src);
        ~ScalarConverter();
        static void detectType(std::string literal);
        static bool is_char(std::string literal);
        static bool is_float(std::string literal);
        static bool is_double(std::string literal);
        static bool is_int(std::string literal);
        static void literal_to_char(std::string literal);
        static void literal_to_int(std::string literal);
        static void literal_to_float(std::string literal);
        static void literal_to_double(std::string literal);
        static bool	handle_pseudo_literals(std::string literal);
};

#endif