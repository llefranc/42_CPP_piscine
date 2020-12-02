/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:56:19 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 16:31:00 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void	firstZombieOnTheStack()
{
	Zombie zombie1("Dylan", "enraged zombie");
	std::cout << "A strange virus striked on human race and transformed an human!\n";
	zombie1.announce();
	std::cout << "Dylan bit Carlos!\n\n";
}

int		secondZombieOnTheStack()
{
	Zombie zombie2("Carlos", "fat zombie");
	zombie2.announce();
	
	//generating a random number of new zombies
	srand(time(NULL));
	int	nbNewZombie = rand() % 4 + 1;
	std::cout << zombie2.getName() << " is really hungry, he bit " << nbNewZombie << " people!\n\n";
	return (nbNewZombie);
}

//nBNewZombies zombies allocated on the heap and free after use
void	zombiesOnTheHeap(int nbNewZombies)
{
	ZombieEvent zombieEvent;
	Zombie *zombiesBitten;
	
	zombieEvent.setZombieType("basic zombie");
	for (int i = 0; i < nbNewZombies; i++)
	{
		zombiesBitten = zombieEvent.randomChump();
		delete zombiesBitten;
	}
}

int main()
{
	int nbNewZombies;

	firstZombieOnTheStack();
	nbNewZombies = secondZombieOnTheStack();
	zombiesOnTheHeap(nbNewZombies);
	return (0);
}
