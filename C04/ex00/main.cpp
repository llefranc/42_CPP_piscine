/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:44:51 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/12 11:18:08 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	
	std::cout << robert << jim << joe;
	
	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << "\n-----TEST POLYMORPH-----\n";
	Victim* ptr = &joe;
	std::cout << robert << jim << *ptr;
	robert.polymorph(*ptr);
	ptr->getPolymorphed();
	
	std::cout << "\n-----TEST COPY-----\n";
	Peon bob("bob");
	bob = joe;
	Victim billy("billy");
	billy = jim;
	Sorcerer henri(robert);
	
	henri.polymorph(bob);
	henri.polymorph(billy);
	std::cout << "Henri is now named " << henri.getName() << "\n";
	
	
	std::cout << "\n-------TEST NAMES-------\n";
	std::cout << jim.getName() << "\n";
	std::cout << ptr->getName() << "\n\n";
	
	return 0;
}