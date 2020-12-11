/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:29:57 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:20:36 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

// Default constructor
PowerFist::PowerFist(const std::string& name, int damage, int apCost) :
	AWeapon(name, damage, apCost) {}
	
// Destructor
PowerFist::~PowerFist() {}
	
// Copy constructor
PowerFist::PowerFist(const PowerFist& copyObj) :
	AWeapon(copyObj) {}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *\n";
}

PowerFist& PowerFist::operator=(PowerFist assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(PowerFist& a, PowerFist& b)
{
	swap(static_cast<AWeapon&>(a), static_cast<AWeapon&>(b));
}