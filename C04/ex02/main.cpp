/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:13:41 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/16 11:36:43 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "ZombieSquad.hpp"

int main()
{
	std::cout << "Scout assault team launched!\n";
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* tom = bob->clone();
	ISquad* vlc = new Squad;
	
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(tom);
	
	std::cout << "\n\nScout assault team meet ennemies!\n";
	std::cout << "-----------------------------------------\n";
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	
	
	std::cout << "\nFirst wave of reinforcements launched:\n";
	Squad reinforcements;
	reinforcements.push(bob->clone());
	reinforcements.push(jim->clone());
	
	std::cout << "\nSecond wave of reinforcements launched:\n";
	Squad reinforcements2(reinforcements);

	std::cout << "\nThird wave of reinforcements launched:\n";
	Squad reinforcements3(reinforcements2);
	std::cout << ">>>> Assignment operator:\n";
	reinforcements3 = reinforcements;


	std::cout << "\n\nFirst wave of reinforcements joined the fight!\n";
	std::cout << "-----------------------------------------\n";
	for (int i = 0; i < reinforcements.getCount(); ++i)
	{
		ISpaceMarine* cur = reinforcements.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "\n\nSecond wave of reinforcements joined the fight!\n";
	std::cout << "-----------------------------------------\n";
	for (int i = 0; i < reinforcements2.getCount(); ++i)
	{
		ISpaceMarine* cur = reinforcements2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "\n\nThird wave of reinforcements joined the fight!\n";
	std::cout << "-----------------------------------------\n";
	for (int i = 0; i < reinforcements3.getCount(); ++i)
	{
		ISpaceMarine* cur = reinforcements3.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	
	// Testing polymorphism on Isquad object
	std::cout << "\n\nSome spacemarines turned into zombies!\n";
	std::cout << "-----------------------------------------\n";
	ISquad* zombieSquad = new ZombieSquad;
	
	ISpaceMarine* zombieBob = new TacticalMarine;
	ISpaceMarine* zombieJim = new AssaultTerminator;
	ISpaceMarine* zombieTom = zombieBob->clone();
	
	zombieSquad->push(zombieBob);
	zombieSquad->push(zombieJim);
	zombieSquad->push(zombieTom);


	std::cout << "\n\nDeleting heap allocation:\n";
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "Spacemarine squad:\n";
	delete vlc;

	std::cout << "\nZombies squad:\n";
	delete zombieSquad;
	
	// The three waves of reinforcements
	std::cout << "\n\nDeleting stack allocation:\n";
	std::cout << "-----------------------------------------\n\n";
	
	return (0);
}