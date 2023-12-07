/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:29:14 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/07 22:44:29 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

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
        static void convert(std::string literal);
        static char convert();
        static int convert();
        static float convert();
        static double convert();
};

#endif