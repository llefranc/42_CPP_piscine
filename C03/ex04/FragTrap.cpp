/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:18:55 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 100, 100, 30, 20, 5, "FR4G-TP")
{
	std::cout << "FragTrap constructor called\n";

	_specialAttacks[0] = "banana";
	_specialAttacks[1] = "sextoy";
	_specialAttacks[2] = "frog";
	_specialAttacks[3] = "beer";
	_specialAttacks[4] = "pen";
}

// Copying private members of the parent (ClapTrap), then private members of the child (FragTrap)
FragTrap::FragTrap(const FragTrap& copyObj) : ClapTrap(copyObj)
{
	std::cout << "FragTrap copy constructor called\n";

	for (int i = 0; i < 5; i++)
		_specialAttacks[i] = copyObj._specialAttacks[i];
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator=(FragTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void FragTrap::rangedAttack(const std::string& target) const
{
	std::cout << "FR4G-TP unit " << _name << " attacks " << target << " at range, causing "
		<< _rangedAttackDamage << " points of damage!\n";
}

void FragTrap::vaulthunterDotExe(const std::string& target)
{
	if (_energyPoints < 25)
	{
		std::cout << _type << " unit " << _name << " doesn't have enough energy to launch his special attack.\n";
		return ;
	}
	
	_energyPoints -= 25;
	std::cout << _type << " unit " << _name << " attacks " << target << " using his special "
		<< _specialAttacks[rand() % 5] << " and killed him ! It costs him 25 energy points, his enery is now "
		<< _energyPoints << ".\n";
}

// Swaping private members of the parent (ClapTrap), then private members of the child (FragTrap)
void swap(FragTrap& first, FragTrap& second)
{
	swap(static_cast<ClapTrap&>(first), static_cast<ClapTrap&>(second));
	std::swap(first._specialAttacks, second._specialAttacks);
}