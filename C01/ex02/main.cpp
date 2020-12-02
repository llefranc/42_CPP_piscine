/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:56:19 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 17:58:26 by lucaslefran      ###   ########.fr       */
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
void	ZombiesOnTheHeap(int nbNewZombies)
{
	ZombieEvent zombieEvent;
	Zombie *zombiesBitten;
	
	zombieEvent.setZombieType("basic zombie");
	for (int i = 0; i < nbNewZombies; i++)
	{
		zombiesBitten = zombieEvent.randomChump();
		delete zombiesBitten;
	}

	//creating a zombie with a specific name using newZombie method
	zombieEvent.setZombieType("beautiful zombie");
	zombiesBitten = zombieEvent.newZombie("Helene");
	std::cout << "\nBut those " << nbNewZombies << " new zombies doesn't care about humans,\n"
	"they're attracted by a special one...\n\n";
	zombiesBitten->announce();
	delete zombiesBitten;
}

int main()
{
	int nbNewZombies;

	firstZombieOnTheStack();
	nbNewZombies = secondZombieOnTheStack();
	ZombiesOnTheHeap(nbNewZombies);
	return (0);
}
