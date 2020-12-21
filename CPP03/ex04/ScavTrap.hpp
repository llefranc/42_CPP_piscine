/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 15:09:22 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

		std::string		_specialChallenges[5];
		
	public:	
	
		// Constructors
		ScavTrap(const std::string& name);
		
		// Copy constructor / destructor / assignment operator
		ScavTrap(const ScavTrap& copyObj);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap assignObj);
	
		// Methods
		void challengeNewcomer(const std::string& target);
		
		friend void swap(ScavTrap& first, ScavTrap& second);
};

#endif