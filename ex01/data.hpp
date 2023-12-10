/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:33:19 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 17:33:27 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

typedef struct s_data
{
    std::string s1;
    int n;
    std::string s2;
} Data;

#endif