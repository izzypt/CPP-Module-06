/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:55:53 by smagalha          #+#    #+#             */
/*   Updated: 2023/12/10 16:38:06 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string user_input;

	if (argv[1] && !argv[2])
	{
		user_input = argv[1];
		ScalarConverter::detectType(user_input); 	
	}
	else
		std::cout << "No aguments provided or too many arguments ..." << std::endl;
	return (0);
}
