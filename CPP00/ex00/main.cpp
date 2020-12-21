/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:00:46 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/11/28 10:35:25 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	trans_upper(std::string str)
{
	for (int i = 0; str[i]; ++i)
		str[i]= toupper(str[i]);
	return (str);
}

int		main(int ac, char **av)
{
	av;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < ac; ++i)
		std::cout << trans_upper(av[i]);
	std::cout << std::endl;
	return (0);
}
