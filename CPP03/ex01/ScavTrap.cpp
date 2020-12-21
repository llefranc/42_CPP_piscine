/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 11:13:07 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name /* = "ScavTrap" */) : _hitPoints(100),
	_maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50), _level(1), _name(name),
	_meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
	std::cout << "ScavTrap constructor called\n";

	_specialChallenges[0] = "eat 1000 bananas";
	_specialChallenges[1] = "run 42 hours";
	_specialChallenges[2] = "drink 50 pints";
	_specialChallenges[3] = "stop talking during 10 hours";
	_specialChallenges[4] = "pretend being a duck during 10 minutes";
}

ScavTrap::ScavTrap(const ScavTrap& copyObj) : _hitPoints(copyObj._hitPoints), _maxHitPoints(copyObj._maxHitPoints),
	_energyPoints(copyObj._energyPoints), _maxEnergyPoints(copyObj._maxEnergyPoints), _level(copyObj._level),
	_name(copyObj._name), _meleeAttackDamage(copyObj._meleeAttackDamage), _rangedAttackDamage(copyObj._rangedAttackDamage),
	_armorDamageReduction(copyObj._armorDamageReduction)
{
	std::cout << "ScavTrap copy constructor called\n";

	for (int i = 0; i < 5; i++)
		_specialChallenges[i] = copyObj._specialChallenges[i];
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void ScavTrap::swap(ScavTrap& first, ScavTrap& second)
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
	std::swap(first._specialChallenges, second._specialChallenges);
}

void ScavTrap::rangedAttack(const std::string& target) const
{
	std::cout << "SC4V-TP " << _name << " attacks " << target << " at range, causing "
		<< _rangedAttackDamage << " points of damage!\n";
}

void ScavTrap::meleeAttack(const std::string& target) const
{
	std::cout << "SC4V-TP " << _name << " attacks " << target << " with a melee attack,"
		" causing " << _meleeAttackDamage << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount <= _armorDamageReduction)
		std::cout << "SC4V-TP " << _name << " was hit by an attack but didn't "
			"lost any HP! His HP are " << _hitPoints << ".\n";
			
	// Losing hitPoints if armorDamageReduction is not enough to protect him
	else
	{
		unsigned int damageTaken = amount - _armorDamageReduction;
		if (damageTaken > _hitPoints)   // HP can't be negative
			damageTaken = _hitPoints;
		_hitPoints -= damageTaken;
		std::cout << "SC4V-TP " << _name << " was hit by an attack and lost " << damageTaken
			<< " HP! His HP are now " << _hitPoints << ".\n";
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	// amount of repair can't be more than _maxHitPoints
	if (amount + _hitPoints > _maxHitPoints)
		amount = _maxHitPoints - _hitPoints;

	if (!amount)
	{
		std::cout << "SC4V-TP " << _name << " is already full life !\n";
		return ;
	}
	_hitPoints += amount;	
	std::cout << "SC4V-TP " << _name << " is reparing himself for " << amount
		<< " HP! His HP are now " << _hitPoints << ".\n";
}

void ScavTrap::beRecharged(unsigned int amount)
{
	// amount of recharge can't be more than _maxEnergyPoints
	if (amount + _energyPoints > _maxEnergyPoints)
		amount = _maxEnergyPoints - _energyPoints;

	if (!amount)
	{
		std::cout << "SC4V-TP " << _name << " is already full energy !\n";
		return ;
	}
	_energyPoints += amount;	
	std::cout << "SC4V-TP " << _name << " is recharging himself for " << amount
		<< " EP! His energy points are now " << _energyPoints << ".\n";	
}

void ScavTrap::challengeNewcomer(const std::string& target)
{
	if (_energyPoints < 25)
	{
		std::cout << "SC4V-TP doesn't have enough energy to launch his special challenge.\n";
		return ;
	}
	
	_energyPoints -= 25;
	std::cout << "SC4V-TP " << _name << " challenges " << target << " to "
		<< _specialChallenges[rand() % 5] << "! It costs him 25 energy points, his enery is now "
		<< _energyPoints << ".\n";
}