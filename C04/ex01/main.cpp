/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:07:03 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/12 12:06:26 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* me = new Character("me");
	
	std::cout << *me;
	
	Enemy* b = new RadScorpion();
	
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	std::cout << *me;
	
	std::cout << "\n-----TESTS RADSCORPION-----\n";
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	
	// Radscopion is killed and so get deleted 
	me->attack(b);
	std::cout << *me;
	
	std::cout << "\n-----TESTS SUPERMUTANT-----\n";
	b = new SuperMutant();

	me->recoverAP();
	me->attack(b);
	me->attack(b);
	
	me->equip(pf);
	std::cout << *me;

	me->attack(b);
	me->attack(b);
	
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	
	// Supermutant is killed and so get deleted 
	me->attack(b);

	delete me;
	delete pf;
	delete pr;
	
	return (0);
}