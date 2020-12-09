/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 15:36:00 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:	
	
		// Constructors
		NinjaTrap(const std::string& name);
		
		// Copy constructor / destructor / assignment operator
		NinjaTrap(const NinjaTrap& copyObj);
		~NinjaTrap();
		NinjaTrap& operator=(const NinjaTrap assignObj);
	
		// Methods
		void ninjaShoebox(ClapTrap& target);
		void ninjaShoebox(ScavTrap& target);
		void ninjaShoebox(FragTrap& target);
		void ninjaShoebox(NinjaTrap& target);

		friend void swap(NinjaTrap& first, NinjaTrap& second);
};

#endif