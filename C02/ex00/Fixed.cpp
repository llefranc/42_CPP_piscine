/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:31:18 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/03 19:43:19 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_rawBits(0)
{
	std::cout << "Default constructor called\n";
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
	std::cout << "getRawBits member function called\n";
	return (m_rawBits);
}

void Fixed::setrawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	m_rawBits = raw;
}

Fixed& Fixed::operator=(const Fixed& copyF)
{
	std::cout << "Assignation operator called\n";
	m_rawBits = copyF.getRawBits();
	return (*this);
}