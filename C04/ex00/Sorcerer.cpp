/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:45:17 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 17:12:48 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

// Default constructor
Sorcerer::Sorcerer(const std::string& name, const std::string& title) :
	_name(name), _title(title)
{
	std::cout << _name << ", " << _title << " is born!\n";
}
	
// Copy constructor
Sorcerer::Sorcerer(const Sorcerer& copyObj) :
	_name(copyObj._name), _title(copyObj._title) {}
	
// Destructor
Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!\n";
}

// Assignment operator= using copy and swap idiom
Sorcerer& Sorcerer::operator=(Sorcerer copyObj)
{
	swap(*this, copyObj);
	return (*this);
}

// For assignment operator =
void swap(Sorcerer& a, Sorcerer& b)
{
	std::swap(a._name, b._name);
	std::swap(a._title, b._title);
}

const std::string& Sorcerer::getName() const
{
	return (_name);
}

const std::string& Sorcerer::getTitle() const
{
	return (_title);
}

void Sorcerer::polymorph(const Victim& victim) const
{
	victim.getPolymorphed();
}


std::ostream& operator<<(std::ostream& output, const Sorcerer& sorcerer)
{
	output << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!\n";
	return (output);
}
