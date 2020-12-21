/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:35:13 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:

		std::string		_specialAttacks[5];
		
	public:	
	
		// Constructors
		FragTrap(const std::string& name);
		
		// Copy constructor / destructor / assignment operator
		FragTrap(const FragTrap& copyObj);
		~FragTrap();
		FragTrap& operator=(const FragTrap assignObj);
	
		// Methods
		void vaulthunterDotExe(const std::string& target);
		// Overload ClapTrap rangedAttack
		void rangedAttack(const std::string& target) const;
		
		friend void swap(FragTrap& first, FragTrap& second);
};

#endif