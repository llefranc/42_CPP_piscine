/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 15:00:26 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name, unsigned int hitPoints /* 100 */,
	unsigned int maxHitPoints /* 100 */, unsigned int energyPoints /* 100 */,
	unsigned int maxEnergyPoints /* 100 */, unsigned int meleeAttackDamage /* 30 */,
	unsigned int rangedAttackDamage /* 20 */, unsigned int armorDamageReduction /* 5 */,
	const std::string& type /* "CL4P-TP" */) : _name(name), _hitPoints(hitPoints),
	_maxHitPoints(maxHitPoints), _energyPoints(energyPoints), _maxEnergyPoints(maxEnergyPoints),
	_meleeAttackDamage(meleeAttackDamage), _rangedAttackDamage(rangedAttackDamage),
	_armorDamageReduction(armorDamageReduction), _type(type), _level(1)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& copyObj) : _name(copyObj._name), _hitPoints(copyObj._hitPoints),
	_maxHitPoints(copyObj._maxHitPoints), _energyPoints(copyObj._energyPoints),
	_maxEnergyPoints(copyObj._maxEnergyPoints), _meleeAttackDamage(copyObj._meleeAttackDamage),
	_rangedAttackDamage(copyObj._rangedAttackDamage), _armorDamageReduction(copyObj._armorDamageReduction),
	_type(copyObj._type), _level(copyObj._level)
{
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void ClapTrap::rangedAttack(const std::string& target) const
{
	std::cout << _type << " unit " << _name << " attacks " << target << " at range, causing "
		<< _rangedAttackDamage << " points of damage!\n";
}

void ClapTrap::meleeAttack(const std::string& target) const
{
	std::cout << _type << " unit " <<  _name << " attacks " << target << " with a melee attack,"
		" causing " << _meleeAttackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= _armorDamageReduction)
		std::cout << _type << " unit " << _name << " was hit by an attack but didn't "
			"lost any HP! His HP are " << _hitPoints << ".\n";
			
	// Losing hitPoints if armorDamageReduction is not enough to protect him
	else
	{
		unsigned int damageTaken = amount - _armorDamageReduction;
		if (damageTaken > _hitPoints)   // HP can't be negative
			damageTaken = _hitPoints;
		_hitPoints -= damageTaken;
		std::cout << _type << " unit " <<  _name << " was hit by an attack and lost " << damageTaken
			<< " HP! His HP are now " << _hitPoints << ".\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// amount of repair can't be more than _maxHitPoints
	if (amount + _hitPoints > _maxHitPoints)
		amount = _maxHitPoints - _hitPoints;

	if (!amount)
	{
		std::cout << _type << " unit " <<  _name << " is already full life !\n";
		return ;
	}
	_hitPoints += amount;	
	std::cout << _type << " unit " <<  _name << " is reparing himself for " << amount
		<< " HP! His HP are now " << _hitPoints << ".\n";
}

void ClapTrap::beRecharged(unsigned int amount)
{
	// amount of recharge can't be more than _maxEnergyPoints
	if (amount + _energyPoints > _maxEnergyPoints)
		amount = _maxEnergyPoints - _energyPoints;

	if (!amount)
	{
		std::cout << _type << " unit " <<  _name << " is already full energy !\n";
		return ;
	}
	_energyPoints += amount;	
	std::cout << _type << " unit " <<  _name << " is recharging himself for " << amount
		<< " EP! His energy points are now " << _energyPoints << ".\n";	
}

void swap(ClapTrap& first, ClapTrap& second)
{
	std::swap(first._name, second._name);
	std::swap(first._energyPoints, second._energyPoints);
	std::swap(first._maxEnergyPoints, second._maxEnergyPoints);
	std::swap(first._meleeAttackDamage, second._meleeAttackDamage);
	std::swap(first._rangedAttackDamage, second._rangedAttackDamage);
	std::swap(first._armorDamageReduction, second._armorDamageReduction);
	std::swap(first._type, second._type);
	std::swap(first._hitPoints, second._hitPoints);
	std::swap(first._maxHitPoints, second._maxHitPoints);
	std::swap(first._level, second._level);
}