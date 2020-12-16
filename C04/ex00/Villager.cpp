/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Villager.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/12 11:07:25 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Villager.hpp"

// Default constructor
Villager::Villager(const std::string& name) : Victim(name)
{
	std::cout << "Hello my friend.\n";
}

// Copy constructor
Villager::Villager(const Villager& copyObj) : Victim(copyObj) {}

// Destructor
Villager::~Villager()
{
	std::cout << "Nooooooooo...\n";
}

// Assignment operator= with swap and copy idiom
Villager& Villager::operator=(Villager assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(Villager& a, Villager& b)
{
	swap(static_cast<Victim&>(a), static_cast<Victim&>(b));
}

void Villager::getPolymorphed() const
{
	std::cout << _name << " has been turned into a green cow!\n";
}