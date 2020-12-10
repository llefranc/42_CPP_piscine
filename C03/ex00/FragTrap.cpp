/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 16:28:57 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name /* = "Claptrap" */) : _hitPoints(100),
	_maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name),
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
	std::cout << "Constructor called\n";

	_specialAttacks[0] = "banana";
	_specialAttacks[1] = "sextoy";
	_specialAttacks[2] = "frog";
	_specialAttacks[3] = "beer";
	_specialAttacks[4] = "pen";
}

FragTrap::FragTrap(const FragTrap& copyObj) : _hitPoints(copyObj._hitPoints), _maxHitPoints(copyObj._maxHitPoints),
	_energyPoints(copyObj._energyPoints), _maxEnergyPoints(copyObj._maxEnergyPoints), _level(copyObj._level),
	_name(copyObj._name), _meleeAttackDamage(copyObj._meleeAttackDamage), _rangedAttackDamage(copyObj._rangedAttackDamage),
	_armorDamageReduction(copyObj._armorDamageReduction)
{
	std::cout << "Copy constructor called\n";

	for (int i = 0; i < 5; i++)
		_specialAttacks[i] = copyObj._specialAttacks[i];
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called\n";
}

FragTrap& FragTrap::operator=(FragTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void FragTrap::swap(FragTrap& first, FragTrap& second)
{
	std::swap(first._hitPoints, second._hitPoints);
	std::swap(first._maxHitPoints, second._maxHitPoints);
	std::swap(first._energyPoints, second._energyPoints);
	std::swap(first._maxEnergyPoints, second._maxEnergyPoints);
	std::swap(first._level, second._level);
	std::swap(first._name, second._name);
	std::swap(first._meleeAttackDamage, second._meleeAttackDamage);
	std::swap(first._rangedAttackDamage, second._rangedAttackDamage);
	std::swap(first._armorDamageReduction, second._armorDamageReduction);
	std::swap(first._specialAttacks, second._specialAttacks);
}

void FragTrap::rangedAttack(const std::string& target) const
{
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing "
		<< _rangedAttackDamage << " points of damage!\n";
}

void FragTrap::meleeAttack(const std::string& target) const
{
	std::cout << "FR4G-TP " << _name << " attacks " << target << " with a melee attack,"
		" causing " << _meleeAttackDamage << " points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount <= _armorDamageReduction)
		std::cout << "FR4G-TP " << _name << " was hit by an attack but didn't "
			"lost any HP! His HP are " << _hitPoints << ".\n";
			
	// Losing hitPoints if armorDamageReduction is not enough to protect him
	else
	{
		unsigned int damageTaken = amount - _armorDamageReduction;
		if (damageTaken > _hitPoints)   // HP can't be negative
			damageTaken = _hitPoints;
		_hitPoints -= damageTaken;
		std::cout << "FR4G-TP " << _name << " was hit by an attack and lost " << damageTaken
			<< " HP! His HP are now " << _hitPoints << ".\n";
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	// amount of repair can't be more than _maxHitPoints
	if (amount + _hitPoints > _maxHitPoints)
		amount = _maxHitPoints - _hitPoints;

	if (!amount)
	{
		std::cout << "FR4G-TP " << _name << " is already full life !\n";
		return ;
	}
	_hitPoints += amount;	
	std::cout << "FR4G-TP " << _name << " is reparing himself for " << amount
		<< " HP! His HP are now " << _hitPoints << ".\n";
}

void FragTrap::beRecharged(unsigned int amount)
{
	// amount of recharge can't be more than _maxEnergyPoints
	if (amount + _energyPoints > _maxEnergyPoints)
		amount = _maxEnergyPoints - _energyPoints;

	if (!amount)
	{
		std::cout << "FR4G-TP " << _name << " is already full energy !\n";
		return ;
	}
	_energyPoints += amount;	
	std::cout << "FR4G-TP " << _name << " is recharging himself for " << amount
		<< " EP! His energy points are now " << _energyPoints << ".\n";	
}

void FragTrap::vaulthunterDotExe(const std::string& target)
{
	if (_energyPoints < 25)
	{
		std::cout << "FR4G-TP doesn't have enough energy to launch his special attack.\n";
		return ;
	}
	
	_energyPoints -= 25;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " using his special "
		<< _specialAttacks[rand() % 5] << " and killed him ! It costs him 25 energy points, his enery is now "
		<< _energyPoints << ".\n";
}