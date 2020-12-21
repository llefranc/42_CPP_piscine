/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:30:47 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(const std::string& name) : ClapTrap(name, 100, 100, 120, 120, 60, 20, 5, "SUP3R-TP"),
	FragTrap(name), NinjaTrap(name)
{
	std::cout << "SuperTrap constructor called\n";
}

void SuperTrap::printattr() const
{
	std::cout << "name: " << _name << std::endl;
	std::cout << "hp: "  << _hitPoints << std::endl;
	std::cout << "max hp: "  << _maxHitPoints << std::endl;
	std::cout << "energy: "  << _energyPoints << std::endl;
	std::cout << "max energy: "  << _maxEnergyPoints << std::endl;
	std::cout << "melee atta: "  << _meleeAttackDamage << std::endl;
	std::cout << "ranged att: "  << _rangedAttackDamage << std::endl;
	std::cout << "armor reduc: "  << _armorDamageReduction << std::endl;
	std::cout << "special att fragtrap: "  << _specialAttacks[0] << std::endl;
}

// Copying private members of grandparent (ClapTrap), then private members of parents (FragTrap / NinjaTrap)
SuperTrap::SuperTrap(const SuperTrap& copyObj) : ClapTrap(copyObj), FragTrap(copyObj), NinjaTrap(copyObj)
{
	std::cout << "SuperTrap copy constructor called\n";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap destructor called\n";
}

SuperTrap& SuperTrap::operator=(SuperTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void SuperTrap::rangedAttack(const std::string& target) const
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string& target) const
{
	NinjaTrap::meleeAttack(target);
}

// Swaping private members of the parent (ClapTrap), then private members of the child (NinjaTrap)
void swap(SuperTrap& first, SuperTrap& second)
{
	swap(static_cast<ClapTrap&>(first), static_cast<ClapTrap&>(second));
	swap(static_cast<FragTrap&>(first), static_cast<FragTrap&>(second));
	swap(static_cast<NinjaTrap&>(first), static_cast<NinjaTrap&>(second));
}