/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:52:02 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 15:13:11 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <time.h>

//Allocates nb zombies with random name
ZombieHorde::ZombieHorde(unsigned int const nb) : m_nbZombie(nb)
{
	//pool of random names
	m_names[0] = "Billy";
	m_names[1] = "Tim";
	m_names[2] = "Jack";
	m_names[3] = "Henri";
	m_names[4] = "Scott";
	
	m_zombieArray = new Zombie [nb];
	
	//generating random names for nb zombie
	srand(time(NULL));
	for (unsigned int i = 0; i < nb; i++)
		m_zombieArray[i].setName(m_names[rand() % 5]);
}

//Deletes the previously allocated zombies
ZombieHorde::~ZombieHorde()
{
	delete[] m_zombieArray;
}

//Prints on cout name and type of each zombies of the horde
void ZombieHorde::announce () const
{
	for (int i = 0; i < m_nbZombie; i++)
		m_zombieArray[i].announce();
}