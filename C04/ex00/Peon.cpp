/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 17:46:06 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

// Default constructor
Peon::Peon(const std::string& name) : Victim(name)
{
	std::cout << "Zog zog.\n";
}

// Copy constructor
Peon::Peon(const Peon& copyObj) : Victim(copyObj) {}

// Destructor
Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

// Assignment operator= with swap and copy idiom
Peon& Peon::operator=(Peon assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(Peon& a, Peon& b)
{
	swap(static_cast<Victim&>(a), static_cast<Victim&>(b));
}

void Peon::getPolymorphed() const
{
	std::cout << _name << "has been turned into a pink pony!\n";
}