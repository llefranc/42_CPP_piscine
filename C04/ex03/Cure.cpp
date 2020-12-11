/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:12:42 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:14:44 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(const std::string& type) :
	AMateria(type) {}

Cure::~Cure() {}

Cure::Cure(const Cure& copyObj) :
	AMateria(copyObj) {}

Cure& Cure::operator=(Cure assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Cure& a, Cure& b)
{
	swap(static_cast<AMateria&>(a), static_cast<AMateria&>(b));
}

Cure* Cure::clone() const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
	AMateria::use(target);
}