/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:12:52 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:13:37 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	
		Cure(const std::string& type = "cure");
		virtual ~Cure();
		
		Cure(const Cure& copyObj);
		Cure& operator=(Cure assignObj);
		friend void swap(Cure& a, Cure& b);
		
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif