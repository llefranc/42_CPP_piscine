/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:30:53 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:	
	
		// Constructors
		SuperTrap(const std::string& name);
		
		// Copy constructor / destructor / assignment operator
		SuperTrap(const SuperTrap& copyObj);
		~SuperTrap();
		SuperTrap& operator=(const SuperTrap assignObj);
	
		// Methods
		void printattr() const;
		void meleeAttack(const std::string& target) const;
		void rangedAttack(const std::string& target) const;


		friend void swap(SuperTrap& first, SuperTrap& second);
};

#endif