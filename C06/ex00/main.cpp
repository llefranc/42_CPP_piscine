/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:20:15 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/21 11:13:50 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "static_cast.hpp"

int main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
	{
		std::cout << "Please enter only one argument\n";
		return (0);
	}
	
	std::string line = av[1];
	
	if (isInt(line))
		transfInt(atoi(line.c_str()));
	else if (isChar(line))
		transfInt(line[0]);
	else if (isDouble(line) || isFloat(line))
		transfDouble(strtod(line.c_str(), NULL));
	else
		std::cout << "Error: the number is incorrect, or his type is not supported\n";

	return (0);
}