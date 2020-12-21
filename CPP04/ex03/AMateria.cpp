/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:13:08 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:16:22 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) :
	_type(type), _xp(0) {}
	
AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& copyObj) :
	_type(copyObj._type), _xp(copyObj._xp) {}
	
AMateria& AMateria::operator=(const AMateria& assignObj)
{
	if (this == &assignObj)
		return (*this);
	this->_xp = assignObj._xp;
	return (*this);
}

void swap(AMateria& a, AMateria& b)
{
	std::swap(a._xp, b._xp);
}

const std::string& AMateria::getType() const //Returns the materia type
{
	return (_type);
}

unsigned int AMateria::getXP() const //Returns the Materia's XP
{
	return (_xp);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}