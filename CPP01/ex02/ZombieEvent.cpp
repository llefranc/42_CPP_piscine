/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:02:03 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 12:26:20 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

//Default constructor
ZombieEvent::ZombieEvent() : m_type("basic zombie")
{
	m_names[0] = "Billy";
	m_names[1] = "Tim";
	m_names[2] = "Jack";
	m_names[3] = "Henri";
	m_names[4] = "Scott";
};

ZombieEvent::ZombieEvent(std::string type) : m_type(type)
{
	m_names[0] = "Billy";
	m_names[1] = "Tim";
	m_names[2] = "Jack";
	m_names[3] = "Henri";
	m_names[4] = "Scott";
};

//Sets the type to @type
void ZombieEvent::setZombieType(std::string const &type)
{
	m_type = type;
}

//Generates a zombie with @name and the type set
Zombie* ZombieEvent::newZombie(std::string const &name)
{
	Zombie *newZombieObject;

	newZombieObject = new Zombie(name, m_type);
	return (newZombieObject);
}

//Generates a zombie with a random name and the type set
Zombie* ZombieEvent::randomChump() const
{
	Zombie *newZombieObject;

	newZombieObject = new Zombie(m_names[rand() % 5], m_type);
	newZombieObject->announce();
	return (newZombieObject);
}