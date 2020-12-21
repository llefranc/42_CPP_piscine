/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:18:45 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

NinjaTrap::NinjaTrap(const std::string& name) : ClapTrap(name, 60, 60, 120, 120, 60, 5, 0, "NINJ4-TP")
{
	std::cout << "NinjaTrap constructor called\n";
}

// Copying private members of the parent (ClapTrap), then private members of the child (NinjaTrap)
NinjaTrap::NinjaTrap(const NinjaTrap& copyObj) : ClapTrap(copyObj)
{
	std::cout << "NinjaTrap copy constructor called\n";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called\n";
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap assignObj)
{
	std::cout << "operator= called\n";
	
	swap(*this, assignObj);
	return (*this);
}

void NinjaTrap::meleeAttack(const std::string& target) const
{
	std::cout << "NINJ4-TP unit " <<  _name << " attacks " << target << " with a melee attack,"
		" causing " << _meleeAttackDamage << " points of damage!\n";
}

// NinjaTrap attacks ClapTrap and makes him loses HP
void NinjaTrap::ninjaShoebox(ClapTrap& target)
{
	std::cout << _type << " unit " << _name << " throws a Shuriken!\n";
	target.takeDamage(30);
}

// NinjaTrap attacks FragTrap and makes him loses HP
void NinjaTrap::ninjaShoebox(FragTrap& target)
{
	std::cout << _type << " unit " << _name << " throws a bomb!\n";
	target.takeDamage(60);
}

// NinjaTrap attacks ScavTrap and makes him loses HP 
void NinjaTrap::ninjaShoebox(ScavTrap& target)
{
	std::cout << _type << " unit " << _name << " throws a chicken!\n";
	target.takeDamage(20);
}

// NinjaTrap falls and loses HP
void NinjaTrap::ninjaShoebox(NinjaTrap& target)
{
	unsigned int damageTaken = 30;
	if (damageTaken > _hitPoints)   // HP can't be negative
		damageTaken = _hitPoints;
	_hitPoints -= damageTaken;
	std::cout << _type << " unit " << target._name << " falls like a retard! He losts " << damageTaken << "HP\n";
}

// Swaping private members of the parent (ClapTrap), then private members of the child (NinjaTrap)
void swap(NinjaTrap& first, NinjaTrap& second)
{
	swap(static_cast<ClapTrap&>(first), static_cast<ClapTrap&>(second));
}