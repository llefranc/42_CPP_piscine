/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:22:17 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 13:02:35 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : m_name("Bob"), m_type("basic zombie") {}

Zombie::Zombie(std::string name, std::string type) : m_name(name), m_type(type) {}

//Prints on cout name and type of the zombie
void Zombie::announce() const
{
	std::cout << "<" << m_name << " (" << m_type << ")> Braiiiiiiinnnssss...\n";
}

//Returns a string containing the name of the zombie
std::string Zombie::getName() const
{
	return (m_name);
}

//Sets a new name for the zombie
void Zombie::setName(std::string const &newName)
{
	m_name = newName;
}
