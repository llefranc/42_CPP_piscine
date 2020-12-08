/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/08 22:46:15 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class FragTrap
{
	private:

		unsigned int	_hitPoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		int				_level;
		std::string		_name;
		int				_meleeAttackDamage;
		int				_rangedAttackDamage;
		unsigned int	_armorDamageReduction;
		std::string		_specialAttacks[5];
		
	public:	
	
		// Constructors
		FragTrap(const std::string& name = "FragTrap");
		
		// Copy constructor / destructor / assignment operator
		FragTrap(const FragTrap& copyObj);
		~FragTrap();
		FragTrap& operator=(const FragTrap assignObj);
		void swap(FragTrap& first, FragTrap& second);
	
		// Methods
		void rangedAttack(const std::string& target);
		void meleeAttack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void beRecharged(unsigned int amount);
		void vaulthunterDotExe(const std::string& target);
};

#endif