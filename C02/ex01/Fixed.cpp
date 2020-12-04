/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:31:18 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/04 11:06:10 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_rawBits(0)
{
	std::cout << "Default constructor called\n";
}

// Creates a fixed object with int nb converted into a fixed number
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called\n";
	
	m_rawBits = nb << m_nbFracBits;
}

// Creates a fixed object with float nb converted into a fixed number
Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called\n";
	
	m_rawBits = (int)(roundf(nb * (1 << m_nbFracBits)));
}

Fixed::Fixed(const Fixed& copyF) 
{
	std::cout << "Copy constructor called\n";
	
	m_rawBits = copyF.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	return (m_rawBits);
}

void Fixed::setrawBits(int const raw)
{
	m_rawBits = raw;
}

// Returns the fixed converted into an int
int Fixed::toInt() const
{
	return (m_rawBits >> m_nbFracBits);
}

// Returns the fixed converted into a float
float Fixed::toFloat() const
{
	return ((float)m_rawBits / (float)(1 << m_nbFracBits));
}

Fixed& Fixed::operator=(const Fixed& copyF)
{
	std::cout << "Assignation operator called\n";
	
	m_rawBits = copyF.getRawBits();
	return (*this);
}

// Outputs the fixed number as a float
std::ostream& operator<<(std::ostream& oStream, const Fixed& fixed)
{
	oStream << fixed.toFloat();
	return (oStream);
}