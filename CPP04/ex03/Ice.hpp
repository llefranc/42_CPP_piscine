/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:21:45 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:13:06 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	
		Ice(const std::string& type = "ice");
		virtual ~Ice();
		
		Ice(const Ice& copyObj);
		Ice& operator=(Ice assignObj);
		friend void swap(Ice& a, Ice& b);
		
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif