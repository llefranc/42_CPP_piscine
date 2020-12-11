/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:07:30 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:21:15 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

// Default constructor
AWeapon::AWeapon(const std::string& name, int damage, int apCost) :
	_name(name), _damage(damage), _apCost(apCost) {}
	
// Destructor
AWeapon::~AWeapon() {}

// Copy constructor
AWeapon::AWeapon(const AWeapon& copyObj) :
	_name(copyObj._name), _damage(copyObj._damage), _apCost(copyObj._apCost) {}
	

AWeapon& AWeapon::operator=(const AWeapon& assignObj)
{
	if (this == &assignObj)
		return (*this);
	_name = assignObj._name;
	_damage = assignObj._damage;
	_apCost = assignObj._apCost;
	return (*this);
}

void swap(AWeapon& a, AWeapon& b)
{
	std::swap(a._name, b._name);
	std::swap(a._damage, b._damage);
	std::swap(a._apCost, b._apCost);
}

const std::string& AWeapon::getName() const
{
	return (_name);
}

int AWeapon::getAPCost() const
{
	return (_apCost);
}

int AWeapon::getDamage() const
{
	return (_damage);
}