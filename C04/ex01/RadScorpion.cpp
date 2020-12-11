/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:28:21 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:44:59 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

// Default constructor
RadScorpion::RadScorpion() :
	Enemy(80, "RadScorpion")
{
	std::cout <<  "* click click click *\n";
}

// Destructor
RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *\n";
}

// Copy constructor
RadScorpion::RadScorpion(const RadScorpion& copyObj) :
	Enemy(copyObj) {}

// Assignment operator= with copy and swap idiom
RadScorpion& RadScorpion::operator=(RadScorpion assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(RadScorpion& a, RadScorpion& b)
{
	swap(static_cast<Enemy&>(a), static_cast<Enemy&>(b));
}