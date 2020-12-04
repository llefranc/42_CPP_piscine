/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:31:35 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/04 10:30:45 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
	
		int m_rawBits;
		static const int m_nbFracBits = 8;
		
	public:

		Fixed();
		Fixed(const Fixed& copyF);
		~Fixed();

		int getRawBits() const;
		void setrawBits(int const raw);

		Fixed& operator=(const Fixed& copyF);
};

#endif