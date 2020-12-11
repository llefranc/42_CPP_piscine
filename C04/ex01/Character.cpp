/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:46:55 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 14:55:34 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character(const std::string& name, unsigned int actionPoints, AWeapon* characWeapon) :
	_name(name), _actionPoints(actionPoints), _characWeapon(characWeapon) {}
	
// Destructor
Character::~Character() {}

// Copy constructor
Character::Character(const Character& copyObj) :
	_name(copyObj._name), _actionPoints(copyObj._actionPoints), _characWeapon(copyObj._characWeapon) {}
	
// Assignment operator= with copy and swap idiom
Character& Character::operator=(Character assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(Character& a, Character& b)
{
	std::swap(a._name, b._name);
	std::swap(a._actionPoints, b._actionPoints);
	std::swap(a._characWeapon, a._characWeapon);
}

const std::string& Character::getName() const
{
	return (_name);
}

int Character::getAp() const
{
	return (_actionPoints);
}

AWeapon* Character::getWeapon() const
{
	return (_characWeapon);
}

void Character::recoverAP()
{
	_actionPoints += 10;
	if (_actionPoints > 40)
		_actionPoints = 40;
	std::cout << _name << " has recover AP! He got now " << _actionPoints << "AP.\n";
}

void Character::equip(AWeapon* aWeapon)
{
	_characWeapon = aWeapon;
}

void Character::attack(Enemy* enemy)
{
	if (!_characWeapon)
	{
		std::cout << _name << " is unarmed, he can't attack!\n";
		return ;
	}
	if (_characWeapon->getAPCost() > _actionPoints)
	{
		std::cout << _name << " doesn't have enough AP to attack!\n";
		return ;
	}
	
	// Doing the attack
	_actionPoints -= _characWeapon->getAPCost();
	std::cout << _name << " attacks " << enemy->getType() << " with a " << _characWeapon->getName() << "\n";
	_characWeapon->attack();
	if (enemy->getHP() < _characWeapon->getDamage())
		delete enemy;
	else
		enemy->takeDamage(_characWeapon->getDamage());
}

std::ostream& operator<<(std::ostream& output, Character& character)
{
	std::cout << character.getName() << " has " << character.getAp() << " AP and ";
	if (!character.getWeapon())
		std::cout << "is unarmed\n";
	else
		std::cout <<  "wields a " << character.getWeapon()->getName() << "\n";
	return (output);
}