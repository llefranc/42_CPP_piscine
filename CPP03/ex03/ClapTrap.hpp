/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 14:49:19 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ClapTrap
{
	protected:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_meleeAttackDamage;
		unsigned int	_rangedAttackDamage;
		unsigned int	_armorDamageReduction;
		std::string		_type;
		unsigned int	_level;
		
	public:	
	
		// Constructor
		ClapTrap(const std::string& name, unsigned int _hitPoints = 100, unsigned int _maxHitPoints = 100,
			unsigned int energyPoints = 100, unsigned int maxEnergyPoints = 100,
			unsigned int meleeAttackDamage = 30, unsigned int rangedAttackDamage = 20,
			unsigned int armorDamageReduction = 5, const std::string& type = "CL4P-TP");
		
		// Copy constructor / destructor / assignment operator=
		ClapTrap(const ClapTrap& copyObj);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap assignObj);
	
		// Methods
		void rangedAttack(const std::string& target) const;
		void meleeAttack(const std::string& target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void beRecharged(unsigned int amount);
		
		friend void swap(ClapTrap& first, ClapTrap& second);
};

#endif