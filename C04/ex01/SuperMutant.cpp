/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:13:36 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 14:58:13 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

// Default constructor
SuperMutant::SuperMutant() :
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!\n";
}

// Destructor
SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh...\n";
}

// Copy constructor
SuperMutant::SuperMutant(const SuperMutant& copyObj) :
	Enemy(copyObj) {}

// Assignment operator= with copy and swap idiom
SuperMutant& SuperMutant::operator=(SuperMutant AssignObj)
{
	swap(*this, AssignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(SuperMutant& a, SuperMutant& b)
{
	swap(static_cast<Enemy&>(a), static_cast<Enemy&>(b));
}

void SuperMutant::takeDamage(int amount)
{
	amount -= 3;
	if (amount < 0)
		return ;
	if (amount > _hp)
		amount = _hp;
	_hp -= amount;
}