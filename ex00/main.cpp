/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:55:53 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/08 21:29:46 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string user_input;

	user_input = argv[1];
	std::cout << user_input << std::endl;
	ScalarConverter::detectType(user_input);    
	return (0);
}
