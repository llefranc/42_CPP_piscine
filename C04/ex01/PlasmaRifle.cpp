/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:07:30 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:20:48 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

// Default constructor
PlasmaRifle::PlasmaRifle(const std::string& name, int damage, int apCost) :
	AWeapon(name, damage, apCost) {}
	
// Destructor
PlasmaRifle::~PlasmaRifle() {}

// Copy constructor
PlasmaRifle::PlasmaRifle(const PlasmaRifle& copyObj) :
	AWeapon(copyObj) {}

void PlasmaRifle::attack() const
{
	std::cout <<  "* piouuu piouuu piouuu *\n";
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(PlasmaRifle& a, PlasmaRifle& b)
{
	swap(static_cast<AWeapon&>(a), static_cast<AWeapon&>(b));
}