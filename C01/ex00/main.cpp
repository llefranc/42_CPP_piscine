/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:02:15 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/11/30 18:48:14 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::cout << "valur ?\n";
	int var;
	std::cin >> var;
	std::cin.ignore();
	std::string str;
	std::cout << "valeur 2\n";
	getline(std::cin, str);
	std::cout << "valeur 3\n";

	std::cin >> var;
	return (0);
}