/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:31:35 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/04 11:09:52 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <math.h>

class Fixed
{
	private:
	
		int m_rawBits;
		static const int m_nbFracBits = 8;
		
	public:

		// Constructors
		Fixed();
		Fixed(int nb);
		Fixed(float nb);
		
		// Copy constructors / operator= / destructor
		Fixed(const Fixed& copyF);
		Fixed& operator=(const Fixed& copyF);
		~Fixed();

		// Methods
		int getRawBits() const;
		void setrawBits(int const raw);
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& oStream, const Fixed& fixed);

#endif