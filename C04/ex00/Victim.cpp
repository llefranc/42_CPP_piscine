/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:56:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 17:36:44 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

// Default constructor
Victim::Victim(const std::string& name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!\n";
}

// Copy constructor
Victim::Victim(const Victim& copyObj) : _name(copyObj._name) {}

// Destructor
Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!\n";
}

// assignment operator= with copy and swap idiom
Victim& Victim::operator=(Victim assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(Victim& a, Victim& b)
{
	std::swap(a._name, b._name);
}

const std::string& Victim::getName() const
{
	return (_name);
}

void Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!\n";
}

std::ostream& operator<<(std::ostream& output, const Victim& victim)
{
	output << "I'm " << victim.getName() << " and I like otters!\n";
	return (output);
}