/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:44:51 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/16 16:31:36 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Villager.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Villager kyle;

	std::cout << robert << jim << joe << kyle;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(kyle);

	std::cout << "\n-----TEST POLYMORPH PEON-----\n";
	Victim* ptr = &joe;
	std::cout << robert << jim << *ptr << kyle;
	robert.polymorph(*ptr);
	ptr->getPolymorphed();

	std::cout << "\n-----TEST POLYMORPH VILLAGER-----\n";
	ptr = &kyle;
	std::cout << robert << jim << joe << *ptr;
	robert.polymorph(*ptr);
	ptr->getPolymorphed();

	std::cout << "\n-----TEST COPY-----\n";
	Peon bob("bob");
	bob = joe;
	Victim billy("billy");
	billy = jim;
	Villager tom("tom");
	tom = kyle;
	Sorcerer henri(robert);

	henri.polymorph(bob);
	henri.polymorph(billy);
	henri.polymorph(tom);
	std::cout << "Henri is now named " << henri.getName() << "\n";


	std::cout << "\n-------TEST NAMES-------\n";
	std::cout << jim.getName() << "\n";
	std::cout << joe.getName() << "\n";
	std::cout << ptr->getName() << "\n\n";

	return (0);
}