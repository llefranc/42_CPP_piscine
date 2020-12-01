/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:02:15 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 16:26:12 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

int main()
{
	Pony Pony1;
	Pony Pony2("red", 301);

	std::cout << "sexe = " << Pony1.get_sex() << std::endl;
	std::cout << "sexe = " << Pony2.get_sex() << std::endl;
	std::cout << "weight = " << Pony2.get_weight() << std::endl;
	std::stoi("1");
	return (0);
}
