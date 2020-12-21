/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:19:16 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 16:11:56 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

int main()
{
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	
	// Polymorphism
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(ice);
	src->learnMateria(cure);
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	
	// Equip tests
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	// Polymorphism
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	
	delete bob;
	delete me;

	Character* jim = new Character("Jim");
	
	AMateria *tmp2 = src->createMateria("ice");
	
	jim->equip(tmp2);
	jim->equip(src->createMateria("ice"));
	jim->equip(src->createMateria("ice"));
	
	// unequip tests
	jim->unequip(0);
	jim->unequip(5);
	delete tmp2;
	
	// equiped at the right place after unequip use
	jim->equip(src->createMateria("cure"));
	
	// copy constructor and assignment operator=
	Character* jim2 = new Character(*jim);
	Character* jim3 = new Character("Henri");
	*jim3 = *jim;

	// learning more materias than array capacity
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice);
	
	// using polymorphism
	jim2->use(0, *jim);
	jim2->use(1, *jim);
	jim2->use(3, *jim);
	std::cout << std::endl;

	// using polymorphism
	jim3->use(0, *jim);
	jim3->use(1, *jim);
	jim3->use(3, *jim);
	std::cout << std::endl;

	// polymorphism with ICharacter and Enemy class
	ICharacter* pedro = new Enemy("pedro");
	pedro->equip(ice);
	pedro->use(0, *jim);
	pedro->unequip(0);


	delete src;
	delete ice;
	delete cure;
	
	delete jim;
	delete jim2;
	delete jim3;
	delete pedro;

	return (0);
}