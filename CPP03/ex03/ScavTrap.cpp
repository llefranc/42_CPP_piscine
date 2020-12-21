/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 15:00:59 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 100, 50, 50, 20, 15, 3, "SC4V-TP")
{
	std::cout << "ScavTrap constructor called\n";

	_specialChallenges[0] = "eat 1000 bananas";
	_specialChallenges[1] = "run 42 hours";
	_specialChallenges[2] = "drink 50 pints";
	_specialChallenges[3] = "stop talking during 10 hours";
	_specialChallenges[4] = "pretend being a duck during 10 minutes";
}

// Copying private members of the parent (ClapTrap), then private members of the child (ScavTrap)
ScavTrap::ScavTrap(const ScavTrap& copyObj) : ClapTrap(copyObj)
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

void ScavTrap::challengeNewcomer(const std::string& target)
{
	if (_energyPoints < 25)
	{
		std::cout << _type << " unit " << _name << " doesn't have enough energy to launch his special challenge.\n";
		return ;
	}
	
	_energyPoints -= 25;
	std::cout << _type << " unit " << _name <<  " challenges " << target << " to "
		<< _specialChallenges[rand() % 5] << "! It costs him 25 energy points, his enery is now "
		<< _energyPoints << ".\n";
}

// Swaping private members of the parent (ClapTrap), then private members of the child (ScavTrap)
void swap(ScavTrap& first, ScavTrap& second)
{
	swap(static_cast<ClapTrap&>(first), static_cast<ClapTrap&>(second));
	std::swap(first._specialChallenges, second._specialChallenges);
}