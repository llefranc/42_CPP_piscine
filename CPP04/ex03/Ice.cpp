/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:26:09 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:12:32 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(const std::string& type) :
	AMateria(type) {}

Ice::~Ice() {}

Ice::Ice(const Ice& copyObj) :
	AMateria(copyObj) {}

Ice& Ice::operator=(Ice assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Ice& a, Ice& b)
{
	swap(static_cast<AMateria&>(a), static_cast<AMateria&>(b));
}

Ice* Ice::clone() const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	AMateria::use(target);
}