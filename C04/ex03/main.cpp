/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:19:16 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 23:02:16 by lucaslefran      ###   ########.fr       */
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

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;

	Character* jim = new Character("Jim");
	
	jim->equip(src->createMateria("ice"));
	jim->equip(src->createMateria("ice"));
	jim->equip(src->createMateria("ice"));
	
	jim->unequip(0);
	jim->unequip(5);
	
	jim->equip(src->createMateria("cure"));
	
	Character* jim2 = new Character(*jim);
	Character* jim3 = new Character("Henri");
	*jim3 = *jim;

	Ice* ice = new Ice();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	
	jim2->use(0, *jim);
	jim2->use(1, *jim);
	jim2->use(3, *jim);

	jim3->use(0, *jim);
	jim3->use(1, *jim);
	jim3->use(3, *jim);

	delete src;
	delete ice;
	
	delete jim;
	delete jim2;
	delete jim3;
	
	return (0);
}